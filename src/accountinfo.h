/*************************************************************************************
 *  Copyright (C) 2013 by Alejandro Fiestas Olivares <afiestas@kde.org>              *
 *                                                                                   *
 *  This program is free software; you can redistribute it and/or                    *
 *  modify it under the terms of the GNU General Public License                      *
 *  as published by the Free Software Foundation; either version 2                   *
 *  of the License, or (at your option) any later version.                           *
 *                                                                                   *
 *  This program is distributed in the hope that it will be useful,                  *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of                   *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                    *
 *  GNU General Public License for more details.                                     *
 *                                                                                   *
 *  You should have received a copy of the GNU General Public License                *
 *  along with this program; if not, write to the Free Software                      *
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA   *
 *************************************************************************************/

#ifndef ACCOUNT_INFO_WIDGET
#define ACCOUNT_INFO_WIDGET

#include <QtCore/QModelIndex>

#include <QtGui/QWidget>
#include "lib/accountmodel.h"

class KJob;
namespace Ui {
    class AccountInfo;
}
class PasswordEdit;
class AccountModel;
class AccountInfo : public QWidget
{
    Q_OBJECT
    public:
        explicit AccountInfo(AccountModel* model, QWidget* parent = 0, Qt::WindowFlags f = 0);
        virtual ~AccountInfo();

        void setModelIndex(const QModelIndex &index);
        QModelIndex modelIndex() const;

        void loadFromModel();
        bool save();

    public Q_SLOTS:
        void hasChanged();
        void openAvatarSlot();
        void clearAvatar();
        void avatarCreated(KJob* job);
        void avatarModelChanged(KJob* job);
        void changePassword();
        void dataChanged(const QModelIndex &index);

    Q_SIGNALS:
        void changed(bool changed);

    private:
        QString cleanName(QString name) const;
        bool validateName(const QString &name) const;
        QString cleanUsername(QString username);
        bool validateUsername(QString username) const;
        QString cleanEmail(QString email);
        bool validateEmail(const QString &email) const;

        QPixmap m_positive;
        QPixmap m_negative;
        Ui::AccountInfo * m_info;
        AccountModel* m_model;
        PasswordEdit *m_passwordEdit;
        QModelIndex m_index;
        QMap<AccountModel::Role, QVariant> m_infoToSave;
};

#endif //ACCOUNT_INFO_WIDGET