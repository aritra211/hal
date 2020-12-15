#pragma once

#include "hal_core/utilities/log.h"
#include "hal_core/netlist/boolean_function.h"
#include "z3++.h"

#include <unordered_map>

namespace hal
{
    class BooleanFunctionWrapper : public BooleanFunction
    {
    public:
        using BooleanFunction::BooleanFunction;

        BooleanFunctionWrapper(const BooleanFunction& bf) : BooleanFunction(bf){};

        z3::expr to_z3_expr(z3::context& c)
        {
            // convert bf variables to z3::expr
            std::unordered_map<std::string, z3::expr> input2expr;

            for (const auto& var : get_variables())
            {
                input2expr.emplace(var, c.bv_const(var.c_str(), 1));
            }

            auto tmp = to_z3_expr_internal(c, input2expr);

            return tmp;
        };

    private:
        z3::expr to_z3_expr_internal(z3::context& c, const std::unordered_map<std::string, z3::expr>& input2expr)
        {
            z3::expr result(c);
            if (is_empty())
            {
                return result;
            }

            if (m_content == content_type::VARIABLE)
            {
                result = input2expr.at(m_variable);
            }
            else if (m_content == content_type::CONSTANT)
            {
                if (m_constant == Value::ZERO)
                {
                    result = c.bv_val(0, 1);
                }
                else if (m_constant == Value::ONE)
                {
                    result = c.bv_val(1, 1);
                }
                else
                {
                    log_error("verification", "unsupported");
                }
            }
            else
            {
                std::vector<z3::expr> terms;

                for (const auto& x : m_operands)
                {
                    terms.push_back(BooleanFunctionWrapper(x).to_z3_expr_internal(c, input2expr));
                }

                result = terms[0];

                for (u32 i = 1; i < terms.size(); ++i)
                {
                    if (m_op == operation::OR)
                    {
                        result = result | terms[i];
                    }
                    else if (m_op == operation::XOR)
                    {
                        result = result ^ terms[i];
                    }
                    else if (m_op == operation::AND)
                    {
                        result = result & terms[i];
                    }
                }
            }

            if (m_invert)
            {
                result = ~result;
            }

            return result;
        }
    };

}    // namespace hal