#ifndef SYMBOLPAINTER_H
#define SYMBOLPAINTER_H

#include <QColor>

class QPainter;
struct MapAirport;

struct MapWaypoint;

struct MapVor;

struct MapNdb;

class SymbolPainter
{
public:
  SymbolPainter();

  void drawAirportSymbol(QPainter *painter, const MapAirport& ap, int x, int y, int size,
                         bool isAirportDiagram, bool fast);

  void drawWaypointSymbol(QPainter *painter, const MapWaypoint& ap, int x, int y, int size, bool fast);
  void drawVorSymbol(QPainter *painter, const MapVor& ap, int x, int y, int size, bool fast);
  void drawNdbSymbol(QPainter *painter, const MapNdb& ap, int x, int y, int size, bool fast);

private:
};

#endif // SYMBOLPAINTER_H