/*****************************************************************************
* Copyright 2015-2017 Alexander Barthel albar965@mailbox.org
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

#include "common/maptypes.h"

#include "atools.h"
#include "common/unit.h"
#include "options/optiondata.h"

#include <QDataStream>
#include <QHash>
#include <QObject>

namespace maptypes {

const static QHash<QString, QString> surfaceMap(
  {
    {"C", QObject::tr("Concrete")},
    {"G", QObject::tr("Grass")},
    {"W", QObject::tr("Water")},
    {"A", QObject::tr("Asphalt")},
    {"CE", QObject::tr("Cement")},
    {"CL", QObject::tr("Clay")},
    {"SN", QObject::tr("Snow")},
    {"I", QObject::tr("Ice")},
    {"D", QObject::tr("Dirt")},
    {"CR", QObject::tr("Coral")},
    {"GR", QObject::tr("Gravel")},
    {"OT", QObject::tr("Oil treated")},
    {"SM", QObject::tr("Steel Mats")},
    {"B", QObject::tr("Bituminous")},
    {"BR", QObject::tr("Brick")},
    {"M", QObject::tr("Macadam")},
    {"PL", QObject::tr("Planks")},
    {"S", QObject::tr("Sand")},
    {"SH", QObject::tr("Shale")},
    {"T", QObject::tr("Tarmac")},
    {"UNKNOWN", QObject::tr("Unknown")},
    {"INVALID", QString()}
  });

/* The higher the better */
const static QHash<QString, int> surfaceQualityMap(
  {
    {"C", 20},
    {"A", 20},
    {"B", 20},
    {"T", 20},
    {"M", 15},
    {"CE", 15},
    {"OT", 15},
    {"BR", 10},
    {"SM", 10},
    {"PL", 10},
    {"GR", 5},
    {"CR", 5},
    {"D", 5},
    {"SH", 5},
    {"CL", 5},
    {"S", 5},
    {"G", 5},
    {"SN", 5},
    {"I", 5},
    {"W", 1},
    {"UNKNOWN", 0},
    {"INVALID", 0}
  });

/* Short size name for gate and full name for others */
const static QHash<QString, QString> parkingMapGate(
  {
    {"INVALID", QObject::tr("Invalid")},
    {"UNKNOWN", QObject::tr("Unknown")},
    {"RGA", QObject::tr("Ramp GA")},
    {"RGAS", QObject::tr("Ramp GA Small")},
    {"RGAM", QObject::tr("Ramp GA Medium")},
    {"RGAL", QObject::tr("Ramp GA Large")},
    {"RC", QObject::tr("Ramp Cargo")},
    {"RMC", QObject::tr("Ramp Mil Cargo")},
    {"RMCB", QObject::tr("Ramp Mil Combat")},
    {"GS", QObject::tr("Small")},
    {"GM", QObject::tr("Medium")},
    {"GH", QObject::tr("Heavy")},
    {"DGA", QObject::tr("Dock GA")},
    {"FUEL", QObject::tr("Fuel")},
    {"V", QObject::tr("Vehicles")}
  });

/* Short size name for parking and full name for others */
const static QHash<QString, QString> parkingMapRamp(
  {
    {"UNKNOWN", QObject::tr("Unknown")},
    {"RGA", QObject::tr("Ramp GA")},
    {"RGAS", QObject::tr("Small")},
    {"RGAM", QObject::tr("Medium")},
    {"RGAL", QObject::tr("Large")},
    {"RC", QObject::tr("Ramp Cargo")},
    {"RMC", QObject::tr("Ramp Mil Cargo")},
    {"RMCB", QObject::tr("Ramp Mil Combat")},
    {"GS", QObject::tr("Gate Small")},
    {"GM", QObject::tr("Gate Medium")},
    {"GH", QObject::tr("Gate Heavy")},
    {"DGA", QObject::tr("Dock GA")},
    {"FUEL", QObject::tr("Fuel")},
    {"V", QObject::tr("Vehicles")}
  });

/* Full name for all parking including type */
const static QHash<QString, QString> parkingTypeMap(
  {
    {"INVALID", QObject::tr("Invalid")},
    {"UNKNOWN", QObject::tr("Unknown")},
    {"RGA", QObject::tr("Ramp GA")},
    {"RGAS", QObject::tr("Ramp GA Small")},
    {"RGAM", QObject::tr("Ramp GA Medium")},
    {"RGAL", QObject::tr("Ramp GA Large")},
    {"RC", QObject::tr("Ramp Cargo")},
    {"RMC", QObject::tr("Ramp Mil Cargo")},
    {"RMCB", QObject::tr("Ramp Mil Combat")},
    {"GS", QObject::tr("Gate Small")},
    {"GM", QObject::tr("Gate Medium")},
    {"GH", QObject::tr("Gate Heavy")},
    {"DGA", QObject::tr("Dock GA")},
    {"FUEL", QObject::tr("Fuel")},
    {"V", QObject::tr("Vehicles")}
  });

const static QHash<QString, QString> parkingNameMap(
  {
    {"INVALID", QObject::tr("Invalid")},
    {"UNKNOWN", QObject::tr("Unknown")},
    {"NONE", QObject::tr("No Parking")},
    {"P", QObject::tr("Parking")},
    {"NP", QObject::tr("N Parking")},
    {"NEP", QObject::tr("NE Parking")},
    {"EP", QObject::tr("E Parking")},
    {"SEP", QObject::tr("SE Parking")},
    {"SP", QObject::tr("S Parking")},
    {"SWP", QObject::tr("SW Parking")},
    {"WP", QObject::tr("W Parking")},
    {"NWP", QObject::tr("NW Parking")},
    {"G", QObject::tr("Gate")},
    {"D", QObject::tr("Dock")},
    {"GA", QObject::tr("Gate A")},
    {"GB", QObject::tr("Gate B")},
    {"GC", QObject::tr("Gate C")},
    {"GD", QObject::tr("Gate D")},
    {"GE", QObject::tr("Gate E")},
    {"GF", QObject::tr("Gate F")},
    {"GG", QObject::tr("Gate G")},
    {"GH", QObject::tr("Gate H")},
    {"GI", QObject::tr("Gate I")},
    {"GJ", QObject::tr("Gate J")},
    {"GK", QObject::tr("Gate K")},
    {"GL", QObject::tr("Gate L")},
    {"GM", QObject::tr("Gate M")},
    {"GN", QObject::tr("Gate N")},
    {"GO", QObject::tr("Gate O")},
    {"GP", QObject::tr("Gate P")},
    {"GQ", QObject::tr("Gate Q")},
    {"GR", QObject::tr("Gate R")},
    {"GS", QObject::tr("Gate S")},
    {"GT", QObject::tr("Gate T")},
    {"GU", QObject::tr("Gate U")},
    {"GV", QObject::tr("Gate V")},
    {"GW", QObject::tr("Gate W")},
    {"GX", QObject::tr("Gate X")},
    {"GY", QObject::tr("Gate Y")},
    {"GZ", QObject::tr("Gate Z")}
  });

const static QHash<QString, QString> parkingDatabaseNameMap(
  {
    {"NO_PARKING", QObject::tr("NONE")},
    {"PARKING", QObject::tr("P")},
    {"N_PARKING", QObject::tr("NP")},
    {"NE_PARKING", QObject::tr("NEP")},
    {"E_PARKING", QObject::tr("EP")},
    {"SE_PARKING", QObject::tr("SEP")},
    {"S_PARKING", QObject::tr("SP")},
    {"SW_PARKING", QObject::tr("SWP")},
    {"W_PARKING", QObject::tr("WP")},
    {"NW_PARKING", QObject::tr("NWP")},
    {"GATE", QObject::tr("G")},
    {"DOCK", QObject::tr("D")},
    {"GATE_A", QObject::tr("GA")},
    {"GATE_B", QObject::tr("GB")},
    {"GATE_C", QObject::tr("GC")},
    {"GATE_D", QObject::tr("GD")},
    {"GATE_E", QObject::tr("GE")},
    {"GATE_F", QObject::tr("GF")},
    {"GATE_G", QObject::tr("GG")},
    {"GATE_H", QObject::tr("GH")},
    {"GATE_I", QObject::tr("GI")},
    {"GATE_J", QObject::tr("GJ")},
    {"GATE_K", QObject::tr("GK")},
    {"GATE_L", QObject::tr("GL")},
    {"GATE_M", QObject::tr("GM")},
    {"GATE_N", QObject::tr("GN")},
    {"GATE_O", QObject::tr("GO")},
    {"GATE_P", QObject::tr("GP")},
    {"GATE_Q", QObject::tr("GQ")},
    {"GATE_R", QObject::tr("GR")},
    {"GATE_S", QObject::tr("GS")},
    {"GATE_T", QObject::tr("GT")},
    {"GATE_U", QObject::tr("GU")},
    {"GATE_V", QObject::tr("GV")},
    {"GATE_W", QObject::tr("GW")},
    {"GATE_X", QObject::tr("GX")},
    {"GATE_Y", QObject::tr("GY")},
    {"GATE_Z", QObject::tr("GZ")},
  });

const static QHash<QString, QString> navTypeNamesVor(
  {
    {"INVALID", QObject::tr("Invalid")},
    {"H", QObject::tr("H")},
    {"L", QObject::tr("L")},
    {"T", QObject::tr("T")},
    {"VH", QObject::tr("H")},
    {"VL", QObject::tr("L")},
    {"VT", QObject::tr("T")},
  });

const static QHash<QString, QString> navTypeNamesVorLong(
  {
    {"INVALID", QObject::tr("Invalid")},
    {"H", QObject::tr("High")},
    {"L", QObject::tr("Low")},
    {"T", QObject::tr("Terminal")},
    {"VH", QObject::tr("High")},
    {"VL", QObject::tr("Low")},
    {"VT", QObject::tr("Terminal")},
  });

const static QHash<QString, QString> navTypeNamesNdb(
  {
    {"INVALID", QObject::tr("Invalid")},
    {"HH", QObject::tr("HH")},
    {"H", QObject::tr("H")},
    {"MH", QObject::tr("MH")},
    {"CP", QObject::tr("CL")},
    {"NHH", QObject::tr("HH")},
    {"NH", QObject::tr("H")},
    {"NMH", QObject::tr("MH")},
    {"NCP", QObject::tr("CL")},
  });

const static QHash<QString, QString> navTypeNamesWaypoint(
  {
    {"INVALID", QObject::tr("Invalid")},
    {"WN", QObject::tr("Named")},
    {"WU", QObject::tr("Unnamed")},
    {"V", QObject::tr("VOR")},
    {"N", QObject::tr("NDB")}
  });

const static QHash<QString, QString> navNames(
  {
    {"INVALID", QObject::tr("Invalid")},
    {"VD", QObject::tr("VORDME")},
    {"V", QObject::tr("VOR")},
    {"D", QObject::tr("DME")},
    {"N", QObject::tr("NDB")},
    {"W", QObject::tr("Waypoint")}
  });

const static QHash<QString, QString> comTypeNames(
  {
    {"INVALID", QObject::tr("Invalid")},
    {"NONE", QObject::tr("None")},
    {"ATIS", QObject::tr("ATIS")},
    {"MC", QObject::tr("Multicom")},
    {"UC", QObject::tr("Unicom")},
    {"CTAF", QObject::tr("CTAF")},
    {"G", QObject::tr("Ground")},
    {"T", QObject::tr("Tower")},
    {"C", QObject::tr("Clearance")},
    {"A", QObject::tr("Approach")},
    {"D", QObject::tr("Departure")},
    {"CTR", QObject::tr("Center")},
    {"FSS", QObject::tr("FSS")},
    {"AWOS", QObject::tr("AWOS")},
    {"ASOS", QObject::tr("ASOS")},
    {"CPT", QObject::tr("Clearance pre Taxi")},
    {"RCD", QObject::tr("Remote Clearance Delivery")}
  });

const static QHash<QString, QString> approachFixTypeToStr(
  {
    {"NONE", QObject::tr("NONE")},
    {"L", QObject::tr("Localizer")},
    {"V", QObject::tr("VOR")},
    {"N", QObject::tr("NDB")},
    {"TN", QObject::tr("Terminal NDB")},
    {"W", QObject::tr("Waypoint")},
    {"TW", QObject::tr("Terminal Waypoint")},
    {"R", QObject::tr("Runway")}
  });

const static QHash<QString, QString> approachTypeToStr(
  {
    {"GPS", QObject::tr("GPS")},
    {"VOR", QObject::tr("VOR")},
    {"NDB", QObject::tr("NDB")},
    {"ILS", QObject::tr("ILS")},
    {"LOC", QObject::tr("Localizer")},
    {"SDF", QObject::tr("SDF")},
    {"LDA", QObject::tr("LDA")},
    {"VORDME", QObject::tr("VORDME")},
    {"NDBDME", QObject::tr("NDBDME")},
    {"RNAV", QObject::tr("RNAV")},
    {"LOCB", QObject::tr("Localizer Backcourse")}
  });

const static QHash<QString, QString> approachLegTypeToStr(
  {
    {"AF", QObject::tr("Arc to fix")},
    {"CA", QObject::tr("Course to altitude")},
    {"CD", QObject::tr("Course to DME distance")},
    {"CF", QObject::tr("Course to fix")},
    {"CI", QObject::tr("Course to intercept")},
    {"CR", QObject::tr("Course to radial termination")},
    {"DF", QObject::tr("Direct to fix")},
    {"FA", QObject::tr("Fix to altitude")},
    {"FC", QObject::tr("Track from fix from distance")},
    {"FD", QObject::tr("Track from fix to DME distance")},
    {"FM", QObject::tr("From fix to manual termination")},
    {"HA", QObject::tr("Hold to altitude")},
    {"HF", QObject::tr("Hold to fix")},
    {"HM", QObject::tr("Hold to manual termination")},
    {"IF", QObject::tr("Initial fix")},
    {"PI", QObject::tr("Procedure turn")},
    {"RF", QObject::tr("Constant radius arc")},
    {"TF", QObject::tr("Track to fix")},
    {"VA", QObject::tr("Heading to altitude termination")},
    {"VD", QObject::tr("Heading to DME distance termination")},
    {"VI", QObject::tr("Heading to intercept")},
    {"VM", QObject::tr("Heading to manual termination")},
    {"VR", QObject::tr("Heading to radial termination")}
  });

int qHash(const maptypes::MapObjectRef& type)
{
  return type.id ^ static_cast<int>(type.type);
}

QString navTypeName(const QString& type)
{
  QString retval = navTypeNameVor(type);
  if(retval.isEmpty())
    retval = navTypeNameNdb(type);
  if(retval.isEmpty())
    retval = navTypeNameVor(type);
  if(retval.isEmpty())
    retval = navTypeNameWaypoint(type);
  return retval;
}

QString navTypeNameVor(const QString& type)
{
  return navTypeNamesVor.value(type);
}

QString navTypeNameVorLong(const QString& type)
{
  return navTypeNamesVorLong.value(type);
}

QString navTypeNameNdb(const QString& type)
{
  return navTypeNamesNdb.value(type);
}

QString navTypeNameWaypoint(const QString& type)
{
  return navTypeNamesWaypoint.value(type);
}

QString navName(const QString& type)
{
  return navNames.value(type);
}

QString surfaceName(const QString& surface)
{
  return surfaceMap.value(surface);
}

int surfaceQuality(const QString& surface)
{
  return surfaceQualityMap.value(surface, 0);
}

QString parkingGateName(const QString& gate)
{
  return parkingMapGate.value(gate);
}

QString parkingRampName(const QString& ramp)
{
  return parkingMapRamp.value(ramp);
}

QString parkingTypeName(const QString& type)
{
  return parkingTypeMap.value(type);
}

QString parkingName(const QString& name)
{
  return parkingNameMap.value(name);
}

QString parkingDatabaseName(const QString& name)
{
  return parkingDatabaseNameMap.value(name);
}

QString parkingNameNumberType(const maptypes::MapParking& parking)
{
  return maptypes::parkingName(parking.name) + " " + QLocale().toString(parking.number) +
         ", " + maptypes::parkingTypeName(parking.type);
}

QString parkingNameForFlightplan(const maptypes::MapParking& parking)
{
  return parkingNameMap.value(parking.name).toUpper() + " " + QString::number(parking.number);
}

bool MapAirport::closed() const
{
  return flags.testFlag(AP_CLOSED);
}

bool MapAirport::hard() const
{
  return flags.testFlag(AP_HARD);
}

bool MapAirport::tower() const
{
  return flags.testFlag(AP_TOWER);
}

bool MapAirport::towerObject() const
{
  return flags.testFlag(AP_TOWER_OBJ);
}

bool MapAirport::apron() const
{
  return flags.testFlag(AP_APRON);
}

bool MapAirport::taxiway() const
{
  return flags.testFlag(AP_TAXIWAY);
}

bool MapAirport::parking() const
{
  return flags.testFlag(AP_PARKING);
}

bool MapAirport::als() const
{
  return flags.testFlag(AP_ALS);
}

bool MapAirport::vasi() const
{
  return flags.testFlag(AP_VASI);
}

bool MapAirport::fence() const
{
  return flags.testFlag(AP_FENCE);
}

bool MapAirport::closedRunways() const
{
  return flags.testFlag(AP_RW_CLOSED);
}

bool MapAirport::empty() const
{
  return !parking() && !taxiway() && !apron() && !addon();
}

bool MapAirport::addon() const
{
  return flags.testFlag(AP_ADDON);
}

bool MapAirport::anyFuel() const
{
  return flags.testFlag(AP_AVGAS) || flags.testFlag(AP_JETFUEL);
}

bool MapAirport::complete() const
{
  return flags.testFlag(AP_COMPLETE);
}

bool MapAirport::soft() const
{
  return flags.testFlag(AP_SOFT);
}

bool MapAirport::softOnly() const
{
  return !flags.testFlag(AP_HARD) && flags.testFlag(AP_SOFT);
}

bool MapAirport::water() const
{
  return flags.testFlag(AP_WATER);
}

bool MapAirport::helipad() const
{
  return flags.testFlag(AP_HELIPAD);
}

bool MapAirport::waterOnly() const
{
  return !flags.testFlag(AP_HARD) && !flags.testFlag(AP_SOFT) && flags.testFlag(AP_WATER);
}

bool MapAirport::helipadOnly() const
{
  return !flags.testFlag(AP_HARD) && !flags.testFlag(AP_SOFT) &&
         !flags.testFlag(AP_WATER) && flags.testFlag(AP_HELIPAD);
}

bool MapAirport::noRunways() const
{
  return !flags.testFlag(AP_HARD) && !flags.testFlag(AP_SOFT) && !flags.testFlag(AP_WATER);
}

bool MapAirport::isVisible(maptypes::MapObjectTypes objectTypes) const
{
  if(addon() && objectTypes.testFlag(maptypes::AIRPORT_ADDON))
    return true;

  if(OptionData::instance().getFlags() & opts::MAP_EMPTY_AIRPORTS &&
     empty() && !waterOnly() && !objectTypes.testFlag(maptypes::AIRPORT_EMPTY))
    return false;

  if(hard() && !objectTypes.testFlag(maptypes::AIRPORT_HARD))
    return false;

  if((softOnly() || waterOnly() || noRunways()) && !objectTypes.testFlag(maptypes::AIRPORT_SOFT))
    return false;

  return true;
}

/* Convert nav_search type */
maptypes::MapObjectTypes navTypeToMapObjectType(const QString& navType)
{
  maptypes::MapObjectTypes type = NONE;
  if(navType == "V" || navType == "VD" || navType == "D")
    type = maptypes::VOR;
  else if(navType == "N")
    type = maptypes::NDB;
  else if(navType == "W")
    type = maptypes::WAYPOINT;
  return type;
}

QString airwayTypeToShortString(MapAirwayType type)
{
  switch(type)
  {
    case maptypes::NO_AIRWAY:
      break;
    case maptypes::VICTOR:
      return QObject::tr("V");

    case maptypes::JET:
      return QObject::tr("J");

    case maptypes::BOTH:
      return QObject::tr("B");

  }
  return QString();
}

QString airwayTypeToString(MapAirwayType type)
{
  switch(type)
  {
    case maptypes::NO_AIRWAY:
      break;
    case maptypes::VICTOR:
      return QObject::tr("Victor");

    case maptypes::JET:
      return QObject::tr("Jet");

    case maptypes::BOTH:
      return QObject::tr("Both");

  }
  return QString();
}

MapAirwayType airwayTypeFromString(const QString& typeStr)
{
  if(typeStr.startsWith("V"))
    return maptypes::VICTOR;
  else if(typeStr.startsWith("J"))
    return maptypes::JET;
  else if(typeStr.startsWith("B"))
    return maptypes::BOTH;
  else
    return maptypes::NO_AIRWAY;
}

QDataStream& operator>>(QDataStream& dataStream, maptypes::RangeMarker& obj)
{
  qint32 types;
  dataStream >> obj.text >> obj.ranges >> obj.center >> types;
  obj.type = static_cast<maptypes::MapObjectTypes>(types);
  return dataStream;
}

QDataStream& operator<<(QDataStream& dataStream, const maptypes::RangeMarker& obj)
{
  dataStream << obj.text << obj.ranges << obj.center << static_cast<qint32>(obj.type);
  return dataStream;
}

QDataStream& operator>>(QDataStream& dataStream, maptypes::DistanceMarker& obj)
{
  dataStream >> obj.text >> obj.color >> obj.from >> obj.to >> obj.magvar >> obj.isRhumbLine >> obj.hasMagvar;
  return dataStream;
}

QDataStream& operator<<(QDataStream& dataStream, const maptypes::DistanceMarker& obj)
{
  dataStream << obj.text << obj.color << obj.from << obj.to << obj.magvar << obj.isRhumbLine << obj.hasMagvar;
  return dataStream;
}

QString vorType(const MapVor& vor)
{
  QString type;
  if(vor.dmeOnly)
    return QObject::tr("DME");
  else if(vor.hasDme)
    return QObject::tr("VORDME");
  else
    return QObject::tr("VOR");
}

QString vorText(const MapVor& vor)
{
  return QObject::tr("%1 %2 (%3)").arg(vorType(vor)).arg(atools::capString(vor.name)).arg(vor.ident);
}

QString ndbText(const MapNdb& ndb)
{
  return QObject::tr("NDB %1 (%2)").arg(atools::capString(ndb.name)).arg(ndb.ident);
}

QString waypointText(const MapWaypoint& waypoint)
{
  return QObject::tr("Waypoint %1").arg(waypoint.ident);
}

QString userpointText(const MapUserpoint& userpoint)
{
  return QObject::tr("User point %1").arg(userpoint.name);
}

QString airwayText(const MapAirway& airway)
{
  return QObject::tr("Airway %1").arg(airway.name);
}

QString airportText(const MapAirport& airport)
{
  return QObject::tr("Airport %1 (%2)").arg(airport.name).arg(airport.ident);
}

QString comTypeName(const QString& type)
{
  return comTypeNames.value(type);
}

bool MapObjectRef::operator==(const MapObjectRef& other) const
{
  return id == other.id && type == other.type;
}

bool MapObjectRef::operator!=(const MapObjectRef& other) const
{
  return !operator==(other);
}

QString magvarText(float magvar)
{
  int decimals = 0;
  if(std::remainder(std::abs(magvar), 1.f) > 0.f)
    decimals = 1;

  if(magvar < -0.04f)
    return QObject::tr("%1°%2").
           arg(QLocale().toString(std::abs(magvar), 'f', decimals)).arg(QObject::tr(" West"));
  else if(magvar > 0.04f)
    // positive" (or "easterly") variation
    return QObject::tr("%1°%2").
           arg(QLocale().toString(magvar, 'f', decimals)).arg(QObject::tr(" East"));
  else
    return "0°";
}

bool isHardSurface(const QString& surface)
{
  return surface == "C" || surface == "A" || surface == "B" || surface == "T";
}

bool isWaterSurface(const QString& surface)
{
  return surface == "W";
}

bool isSoftSurface(const QString& surface)
{
  return !isWaterSurface(surface) && !isHardSurface(surface);
}

QString parkingShortName(const QString& name)
{
  if(name == "P")
    return QObject::tr("P");
  else if(name == "NP")
    return QObject::tr("N");
  else if(name == "NEP")
    return QObject::tr("NE");
  else if(name == "EP")
    return QObject::tr("E");
  else if(name == "SEP")
    return QObject::tr("SE");
  else if(name == "SP")
    return QObject::tr("S");
  else if(name == "SWP")
    return QObject::tr("SW");
  else if(name == "WP")
    return QObject::tr("W");
  else if(name == "NWP")
    return QObject::tr("NW");
  else if(name == "G")
    return QString();
  else if(name == "D")
    return QObject::tr("D");
  else if(name.startsWith("G"))
    return name.right(1);
  else
    return QString();
}

bool MapSearchResult::isEmpty(const MapObjectTypes& types) const
{
  bool filled = false;
  filled |= types & maptypes::AIRPORT && !airports.isEmpty();
  filled |= types & maptypes::WAYPOINT && !waypoints.isEmpty();
  filled |= types & maptypes::VOR && !vors.isEmpty();
  filled |= types & maptypes::NDB && !ndbs.isEmpty();
  filled |= types & maptypes::AIRWAY && !airways.isEmpty();
  filled |= types & maptypes::USER && !userPoints.isEmpty();
  return !filled;
}

QString approachFixType(const QString& type)
{
  return approachFixTypeToStr.value(type);
}

QString approachType(const QString& type)
{
  return approachTypeToStr.value(type);
}

QString edgeLights(const QString& type)
{
  if(type == "L")
    return QObject::tr("Low");
  else if(type == "M")
    return QObject::tr("Medium");
  else if(type == "H")
    return QObject::tr("High");
  else
    return QString();
}

QString patternDirection(const QString& type)
{
  if(type == "L")
    return QObject::tr("Left");
  else if(type == "R")
    return QObject::tr("Right");
  else
    return QString();
}

QString legType(const QString& type)
{
  return approachLegTypeToStr.value(type);
}

QString altText(const QString& descriptor, float alt1, float alt2)
{
  if(alt1 == 0.f)
    return QString();

  if(descriptor == "+")
    return QObject::tr("At or above %1").arg(Unit::altFeet(alt1));
  else if(descriptor == "-")
    return QObject::tr("At or below %1").arg(Unit::altFeet(alt1));
  else if(descriptor == "A")
    return QObject::tr("At %1").arg(Unit::altFeet(alt1));
  else if(descriptor == "B")
    return QObject::tr("At or above %1 and at or below %2").arg(Unit::altFeet(alt1)).arg(Unit::altFeet(alt2));
  else
    return QObject::tr("At %1").arg(Unit::altFeet(alt1));
}

} // namespace types
