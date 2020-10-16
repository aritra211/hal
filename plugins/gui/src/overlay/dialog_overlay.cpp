#include "gui/overlay/dialog_overlay.h"

#include "gui/dialogs/dialog.h"

namespace hal
{
    DialogOverlay::DialogOverlay(QWidget* parent) : Overlay(parent),
        m_dialog(nullptr)
    {
    }

    void DialogOverlay::set_dialog(Dialog* dialog)
    {
        if (m_dialog)
        {
            m_dialog->hide();
            m_dialog->setParent(nullptr);
        }

        m_dialog = dialog;

        dialog->setParent(this);
        dialog->show();

        connect(dialog, &Dialog::offset_changed, this, &DialogOverlay::position_dialog);
    }

    void DialogOverlay::resizeEvent(QResizeEvent* event)
    {
        Q_UNUSED(event)

        position_dialog();
    }

    void DialogOverlay::position_dialog()
    {
        int x = width() / 2 - m_dialog->width() / 2 + m_dialog->x_offset();
        int y = height() / 2 - m_dialog->height() / 2 + m_dialog->y_offset();

        m_dialog->move(x, y);
    }
}
