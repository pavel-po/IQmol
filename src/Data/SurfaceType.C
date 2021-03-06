/*******************************************************************************

  Copyright (C) 2011-2015 Andrew Gilbert

  This file is part of IQmol, a free molecular visualization program. See
  <http://iqmol.org> for more details.

  IQmol is free software: you can redistribute it and/or modify it under the
  terms of the GNU General Public License as published by the Free Software
  Foundation, either version 3 of the License, or (at your option) any later
  version.

  IQmol is distributed in the hope that it will be useful, but WITHOUT ANY
  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
  FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
  details.

  You should have received a copy of the GNU General Public License along
  with IQmol.  If not, see <http://www.gnu.org/licenses/>.

********************************************************************************/

#include "SurfaceType.h"
#include <QDebug>


namespace IQmol {
namespace Data {

QString SurfaceType::toString() const 
{
   QString label;
   switch (m_kind) {
      case Custom:                 label = "Custom";                  break;
      case AlphaOrbital:           label = "Alpha";                   break;
      case BetaOrbital:            label = "Beta";                    break;
      case TotalDensity:           label = "Total Density";           break;
      case SpinDensity:            label = "Spin Density";            break;
      case AlphaDensity:           label = "Alpha Density";           break;
      case BetaDensity:            label = "Beta Density";            break;
      case DensityCombo:           label = "User Defined Density";    break;
      case CubeData:               label = "Cube Data";               break;
      case VanDerWaals:            label = "van der Waals";           break;
      case Promolecule:            label = "Promolecule";             break;
      case SolventExcluded:        label = "Solvent Excluded";        break;
      case SID:                    label = "SID";                     break;
      case ElectrostaticPotential: label = "Electrostatic Potential"; break;
   }

   if (m_kind == AlphaOrbital || m_kind == BetaOrbital) {
      label += " " + QString::number(m_index);
   }
   return label;
}


bool SurfaceType::isOrbital() const
{
   return (m_kind == AlphaOrbital) || (m_kind == BetaOrbital);
}


bool SurfaceType::isDensity() const
{
   return (m_kind == AlphaDensity) || (m_kind == BetaDensity) ||
          (m_kind == TotalDensity) || (m_kind == SpinDensity) ||
          (m_kind == DensityCombo);
}


bool SurfaceType::isSigned() const
{
   return (m_kind == AlphaOrbital) || (m_kind == BetaOrbital) ||
          (m_kind == SpinDensity)  || (m_kind == DensityCombo);
}


void SurfaceType::dump() const 
{
   qDebug() << toString();
}

} } // end namespace IQmol::Data
