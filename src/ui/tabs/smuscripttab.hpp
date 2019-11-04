/*
 * This file is part of the SmuView project.
 *
 * Copyright (C) 2019 Frank Stettner <frank-stettner@gmx.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef UI_TABS_SMUSCRIPTTAB_HPP
#define UI_TABS_SMUSCRIPTTAB_HPP

#include <memory>

#include <QAction>
#include <QMainWindow>
#include <QToolBar>

#include "src/ui/tabs/basetab.hpp"

using std::shared_ptr;
using std::string;

namespace sv {

class Session;

namespace python {
class SmuScriptRunner;
}

namespace ui {

namespace widgets {
namespace scripteditor {
class SmuScriptEditor;
}
}

namespace tabs {

class SmuScriptTab : public BaseTab
{
	Q_OBJECT

private:

public:
	SmuScriptTab(Session &session,
		string script_file_name, QMainWindow *parent);

private:
	void setup_ui();
	void setup_toolbar();

	string script_file_name_;
	QAction *const action_open_;
	QAction *const action_save_;
	QAction *const action_run_;
	QToolBar *toolbar_;
	shared_ptr<python::SmuScriptRunner> smu_script_runner_; // TODO: Use unique_ptr instead?
	widgets::scripteditor::SmuScriptEditor *editor_;

private Q_SLOTS:
	void on_action_open_triggered();
	void on_action_save_triggered();
	void on_action_run_triggered();
	void on_script_error(QString);

};

} // namespace tabs
} // namespace ui
} // namespace sv

#endif // UI_TABS_SMUSCRIPTTAB_HPP