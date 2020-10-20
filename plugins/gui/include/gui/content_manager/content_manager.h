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

#include "gui/netlist_watcher/netlist_watcher.h"

#include <QObject>
#include <QStringList>

namespace hal
{
    class MainWindow;
    class ContentWidget;
    class PythonConsoleWidget;
    class PythonEditor;
    class GraphTabWidget;
    class ContextManagerWidget;
    class NetlistWatcher;
    class SelectionDetailsWidget;

    class ContentManager final : public QObject
    {
        Q_OBJECT

    public:
        explicit ContentManager(MainWindow* parent);
        ~ContentManager();

        PythonEditor* get_python_editor_widget();
        GraphTabWidget* get_graph_tab_widget();
        ContextManagerWidget* get_context_manager_widget();
        SelectionDetailsWidget* get_selection_details_widget();

        void close_content();

    public Q_SLOTS:
        void handle_open_document(const QString& file_name);

    private:
        MainWindow* m_main_window;

        NetlistWatcher* m_netlist_watcher;

        QList<ContentWidget*> m_content;

        PythonEditor* m_python_widget;

        PythonConsoleWidget* m_python_console_widget;
        GraphTabWidget* m_graph_tab_wid;
        ContextManagerWidget* m_context_manager_wid;
        SelectionDetailsWidget* m_selection_details_widget;
    };
}
