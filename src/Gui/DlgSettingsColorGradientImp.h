/***************************************************************************
 *   Copyright (c) 2005 Werner Mayer <wmayer[at]users.sourceforge.net>     *
 *                                                                         *
 *   This file is part of the FreeCAD CAx development system.              *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Library General Public           *
 *   License as published by the Free Software Foundation; either          *
 *   version 2 of the License, or (at your option) any later version.      *
 *                                                                         *
 *   This library  is distributed in the hope that it will be useful,      *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Library General Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this library; see the file COPYING.LIB. If not,    *
 *   write to the Free Software Foundation, Inc., 59 Temple Place,         *
 *   Suite 330, Boston, MA  02111-1307, USA                                *
 *                                                                         *
 ***************************************************************************/


#ifndef GUI_DIALOG_DLGSETTINGSCOLORGRADIENT_IMP_H
#define GUI_DIALOG_DLGSETTINGSCOLORGRADIENT_IMP_H

#include <App/ColorModel.h>
#include <QDialog>
#include <memory>

class QDoubleValidator;

namespace Gui {
namespace Dialog {
class Ui_DlgSettingsColorGradient;

/**
 * The DlgSettingsColorGradientImp class implements a preference page to change settings
 * for the color gradient bar.
 * @author Werner Mayer
 */
class DlgSettingsColorGradientImp : public QDialog
{
    Q_OBJECT

public:
    DlgSettingsColorGradientImp( QWidget* parent = nullptr, Qt::WindowFlags fl = Qt::WindowFlags() );
    ~DlgSettingsColorGradientImp();

    void accept();

    /** @name Color model */
    //@{
    void setColorModel(std::size_t tModel);
    std::size_t colorModel() const;
    void setColorModelNames(const std::vector<std::string>&);
    //@}
    /** @name Color style */
    //@{
    void setColorStyle( App::ColorGradient::TStyle tStyle );
    App::ColorGradient::TStyle colorStyle() const;
    //@}
    /** @name Display mode */
    //@{
    void setOutGrayed( bool grayed );
    bool isOutGrayed() const;
    void setOutInvisible( bool invisible );
    bool isOutInvisible() const;
    //@}
    /** @name Parameter range and scale */
    //@{
    void setRange( float fMin, float fMax );
    void getRange( float& fMin, float& fMax) const;
    void setNumberOfLabels(int);
    int numberOfLabels() const;
    void setNumberOfDecimals(int);
    int numberOfDecimals() const;
    //@}

private:
    std::unique_ptr<Ui_DlgSettingsColorGradient> ui;
    QDoubleValidator* fMaxVal;
    QDoubleValidator* fMinVal;
};

} // namespace Dialog
} // namespace Gui

#endif // GUI_DIALOG_DLGSETTINGSCOLORGRADIENT_IMP_H
