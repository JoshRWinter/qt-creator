/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
****************************************************************************/

#pragma once

#include "idevicefwd.h"
#include <projectexplorer/projectexplorer_export.h>
#include <utils/id.h>

#include <QIcon>
#include <QVariantMap>

namespace Utils { class FilePath; }

namespace ProjectExplorer {

class PROJECTEXPLORER_EXPORT IDeviceFactory
{
public:
    virtual ~IDeviceFactory();
    static const QList<IDeviceFactory *> allDeviceFactories();

    Utils::Id deviceType() const { return m_deviceType; }
    QString displayName() const { return m_displayName; }
    QIcon icon() const { return m_icon; }
    bool canCreate() const;
    IDevicePtr construct() const;
    IDevicePtr create() const;

    virtual bool canRestore(const QVariantMap &) const { return true; }

    static IDeviceFactory *find(Utils::Id type);

protected:
    explicit IDeviceFactory(Utils::Id deviceType);
    IDeviceFactory(const IDeviceFactory &) = delete;
    IDeviceFactory &operator=(const IDeviceFactory &) = delete;

    void setDisplayName(const QString &displayName);
    void setIcon(const QIcon &icon);
    void setCombinedIcon(const Utils::FilePath &small, const Utils::FilePath &large);
    void setConstructionFunction(const std::function<IDevicePtr ()> &constructor);
    void setCreator(const std::function<IDevicePtr()> &creator);

private:
    std::function<IDevicePtr()> m_creator;
    const Utils::Id m_deviceType;
    QString m_displayName;
    QIcon m_icon;
    std::function<IDevicePtr()> m_constructor;
};

} // namespace ProjectExplorer
