/*
Copyright (C) 2015 - 2015 Evan Teran
                          evan.teran@gmail.com

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef GRAPH_EDGE_H_20090903_
#define GRAPH_EDGE_H_20090903_

#include <QColor>
#include <QGraphicsItemGroup>
#include <graphviz/cgraph.h>
#include <graphviz/gvc.h>

class GraphWidget;
class GraphNode;
class GraphicsLineItem;

class GraphEdge final : public QGraphicsItemGroup {
public:
	GraphEdge(GraphNode *from, GraphNode *to, const QColor &color = Qt::black, QGraphicsItem *parent = nullptr);
	GraphEdge(const GraphEdge &) = delete;
	GraphEdge &operator=(const GraphEdge &) = delete;
	~GraphEdge() override;

public:
	enum { Type = UserType + 3 };

	int type() const override {
		// Enable the use of qgraphicsitem_cast with this item.
		return Type;
	}

public:
	GraphNode *from() const;
	GraphNode *to() const;
	void clear();
	void syncState();

public:
	int lineThickness() const;
	QColor lineColor() const;

public:
	void updateLines();

protected:
	void createLine();
	QGraphicsPolygonItem *addArrowHead(const QLineF &line);
	QGraphicsPolygonItem *addArrowHead(const QLineF &line, int lineThickness, const QColor &color, int ZValue);
	QLineF shortenLineToNode(QLineF line);
	QGraphicsLineItem *createLineSegment(const QPointF &p1, const QPointF &p2, const QPen &pen);
	QGraphicsLineItem *createLineSegment(const QLineF &line, const QPen &pen);

protected:
	GraphNode *from_    = nullptr;
	GraphNode *to_      = nullptr;
	GraphWidget *graph_ = nullptr;
	Agedge_t *edge_     = nullptr;
	QColor color_;
};

#endif
