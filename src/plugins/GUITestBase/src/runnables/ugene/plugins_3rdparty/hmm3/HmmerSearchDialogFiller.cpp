/**
 * UGENE - Integrated Bioinformatics Tools.
 * Copyright (C) 2008-2022 UniPro <ugene@unipro.ru>
 * http://ugene.net
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

#include <primitives/GTLineEdit.h>
#include <primitives/GTRadioButton.h>
#include <primitives/GTWidget.h>

#include <QApplication>

#include "HmmerSearchDialogFiller.h"
namespace U2 {

#define GT_CLASS_NAME "UHMM3SearchDialogFiller"
#define GT_METHOD_NAME "run"

void HmmerSearchDialogFiller::commonScenario() {
    QWidget* dialog = GTWidget::getActiveModalWidget(os);

    auto queryHmmFileEdit = GTWidget::findLineEdit(os, "queryHmmFileEdit", dialog);
    GTLineEdit::setText(os, queryHmmFileEdit, profile);

    auto radio = GTWidget::findRadioButton(os, "rbCreateNewTable", dialog);
    GTRadioButton::click(os, radio);

    auto newFilePathle = GTWidget::findLineEdit(os, "leNewTablePath", dialog);
    GTLineEdit::setText(os, newFilePathle, newFilePath);

    GTUtilsDialog::clickButtonBox(os, dialog, QDialogButtonBox::Ok);
}

#undef GT_METHOD_NAME
#undef GT_CLASS_NAME
}  // namespace U2
