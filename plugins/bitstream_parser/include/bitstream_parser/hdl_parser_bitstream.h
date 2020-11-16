//  MIT License
//
//  Copyright (c) 2019 Ruhr-University Bochum, Germany, Chair for Embedded Security. All Rights reserved.
//  Copyright (c) 2019 Marc Fyrbiak, Sebastian Wallat, Max Hoffmann ("ORIGINAL AUTHORS"). All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.

#pragma once

#include "hal_core/utilities/token_stream.h"
#include "hal_core/defines.h"
#include "bitstream_parser/hdl_parser_template.h"
#include "hal_core/plugin_system/plugin_interface_cli.h"
#include "hal_core/netlist/module.h"
#include "hal_core/netlist/net.h"

#include <optional>
#include <unordered_map>
#include <unordered_set>
#include <utility>

namespace hal
{
    /**
     * @ingroup hdl_parsers
     */
    class HDL_PARSER_API HDLParserBitstream : public HDLParserTemplate<core_strings::CaseInsensitiveString>
    {
    public:
        HDLParserBitstream() = default;
        ~HDLParserBitstream() = default;

        /**
         * Parses a Xilinx bitstream file to netlist and then into an intermediate format.
         *
         * @param[in] stream - The string stream filled with the hdl code.
         * @returns True on success, false otherwise.
         */
        bool parse(std::stringstream& stream) override;
    };
}    // namespace hal
