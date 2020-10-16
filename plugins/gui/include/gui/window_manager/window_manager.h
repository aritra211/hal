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

#include <QList>
#include <QObject>

class QAction;

namespace hal
{
    class Dialog;
    class MainSettingsWidget;
    class PluginScheduleWidget;
    class WelcomeScreen;
    class Window;
    class WindowToolbar;

    class WindowManager final : public QObject
    {
        Q_OBJECT

    public:
        explicit WindowManager(QObject* parent = nullptr);

        void setup();

        void add_window();
        void remove_window(Window* window);

        void set_main_window(Window* window);

        void lock_windows();
        void unlock_windows();

        void queue_dialog(Dialog* dialog);
        void delete_dialog(Dialog* dialog);

        void save_layout(const QString& name);
        void restore_layout(const QString& name);

        void handle_window_close_request(Window* window);

        void repolish();

    public Q_SLOTS:
        void handle_overlay_clicked();

    private Q_SLOTS:
        void handle_action_open();
        void handle_action_close();
        void handle_action_save();
        void handle_action_schedule();
        void handle_action_run_schedule();
        void handle_action_content();
        void handle_action_settings();
        void handle_action_about();

    private:
        Window* m_main_window;
        QList<Window*> m_windows;

        WindowToolbar* m_toolbar;

        QAction* m_action_open_file;
        QAction* m_action_close_file;
        QAction* m_action_save;
        QAction* m_action_schedule;
        QAction* m_action_run_schedule;
        QAction* m_action_content;
        QAction* m_action_settings;
        QAction* m_action_about;

        QList<Dialog*> m_dialogs;

        WelcomeScreen* m_welcome_screen;
        PluginScheduleWidget* m_plugin_schedule_widget;
        MainSettingsWidget* m_main_settings_widget;

        bool m_switch_main_on_focus;
    };
}
