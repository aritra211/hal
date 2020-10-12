#include "gui/notifications/notification_manager.h"
#include "gui/notifications/notification.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QScreen>

#include <cassert>

namespace hal
{
    NotificationManager::NotificationManager(QObject* parent) : QObject(parent),
        m_width_offset(20),
        m_height_offset(20),
        m_spacing(10),
        m_timeout(15000)
    {
        m_timer.setSingleShot(true);

        QObject::connect(&m_timer, &QTimer::timeout, this, &NotificationManager::handle_timeout);
    }

    void NotificationManager::remove(Notification* n)
    {
        assert(n);
        assert(m_notifications.contains(n));

        if (m_notifications.removeOne(n))
        {
            n->hide();
            delete n;
        }
        rearrange_Notifications();
    }

    void NotificationManager::debug_add_Notification()
    {
        Notification* n = new Notification(nullptr);
        m_notifications.append(n);
        rearrange_Notifications();
        n->fade_in();
        QApplication::beep();

        if (m_timeout)
        {
            if (m_timer.isActive())
            {
                // INCORRECT IF TIMEOUT VALUE GETS CHANGED WHILE NOTIFICATIONS ARE ACTIVE BUT HONESTLY WHO CARES
                m_timeouts.append(m_timeout - m_timer.remainingTime());
            }
            else
            {
                m_timer.setInterval(m_timeout);
                m_timer.start();
            }
        }
    }

    void NotificationManager::handle_timeout()
    {
        remove(m_notifications.first());

        if (!m_timeouts.isEmpty())
        {
            m_timer.setInterval(m_timeouts.first());
            m_timeouts.removeFirst();
            m_timer.start();
        }
    }

    void NotificationManager::rearrange_Notifications()
    {
        QRect rect = QApplication::primaryScreen()->availableGeometry();

        int y = m_height_offset;

        for (auto& element : m_notifications)
        {
            y += element->height();
            element->move(rect.width() - m_width_offset - element->width() + rect.x(), rect.height() - y + rect.y());
            y += m_spacing;
        }
    }
}
