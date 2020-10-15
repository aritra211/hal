#include "gui/notifications/notification_manager.h"
#include "gui/notifications/notification.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QScreen>

#include <cassert>
#include <chrono>

namespace hal
{
    NotificationManager::NotificationManager(QObject* parent) : QObject(parent),
        m_width_offset(20),
        m_height_offset(20),
        m_spacing(10),
        m_timeout(15000)
    {
        QObject::connect(&m_timer, &QTimer::timeout, this, &NotificationManager::handle_timeout);

        m_timer.setInterval(100);
    }

    void NotificationManager::remove(Notification* n)
    {
        assert(n);
        //assert(m_list.contains(n));

        for (int i = 0; i < m_list.size(); ++i)
        {
            if (m_list.at(i).first == n)
            {
                m_list.removeAt(i);

                if (m_list.isEmpty())
                    m_timer.stop();

                n->hide();
                delete n;

                rearrange_Notifications();
                break;
            }
        }
    }

    void NotificationManager::debug_add_Notification()
    {
        if (m_timeout)
            if (m_list.isEmpty())
                m_timer.start();

        Notification* n = new Notification(nullptr);
        std::chrono::system_clock::time_point t = std::chrono::system_clock::now() + std::chrono::milliseconds(m_timeout);

        m_list.append(QPair<Notification*, std::chrono::system_clock::time_point>(n, t));

        rearrange_Notifications();
        n->fade_in();
        QApplication::beep();
    }

    void NotificationManager::handle_timeout()
    {
        std::chrono::system_clock::time_point t = std::chrono::system_clock::now();

        // INEFFICIENT BUT SIMPLE

        int i = 0;

        for (; i < m_list.size(); ++i)
        {
            if (t < m_list.at(i).second)
                break;
        }

        for (; i > 0; --i)
            remove(m_list.first().first);
    }

    void NotificationManager::rearrange_Notifications()
    {
        QRect rect = QApplication::primaryScreen()->availableGeometry();

        int y = m_height_offset;

        for (const QPair<Notification*, std::chrono::system_clock::time_point>& pair : m_list)
        {
            Notification* n = pair.first;

            y += n->height();
            n->move(rect.width() - m_width_offset - n->width() + rect.x(), rect.height() - y + rect.y());
            y += m_spacing;
        }
    }
}
