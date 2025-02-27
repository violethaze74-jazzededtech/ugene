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

#ifndef _U2_CREATE_RECTANGULAR_BRANCHES_TASK_H_
#define _U2_CREATE_RECTANGULAR_BRANCHES_TASK_H_

#include "CreateBranchesTask.h"

namespace U2 {

class PhyNode;
class GraphicsRectangularBranchItem;

class CreateRectangularBranchesTask : public CreateBranchesTask {
    Q_OBJECT
public:
    CreateRectangularBranchesTask(const PhyNode* n);
    void run() override;

    TreeLayout getLayoutType() const override {
        return RECTANGULAR_LAYOUT;
    }

    qreal getScale() const {
        return scale;
    }

private:
    int size;
    int current;
    qreal scale;
    const PhyNode* node;
    qreal minDistance, maxDistance;
    GraphicsRectangularBranchItem* getBranch(const PhyNode* node);
};

}  // namespace U2

#endif
