/*
Copyright (C) 2006 - 2016 Evan Teran
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

#ifndef SYNTAX_HIGHLIGHTER_H_20191119_
#define SYNTAX_HIGHLIGHTER_H_20191119_

#include <QRegExp>
#include <QTextCharFormat>
#include <QTextLayout>
#include <QVector>
#include <vector>

class SyntaxHighlighter : public QObject {
	Q_OBJECT

public:
	explicit SyntaxHighlighter(QObject *parent = nullptr);

private:
	void createRules();

public:
	QVector<QTextLayout::FormatRange> highlightBlock(const QString &text);

private:
	struct HighlightingRule {
		HighlightingRule();
		HighlightingRule(const QString &regex, const QBrush &foreground, const QBrush &background, int weight, bool italic, bool underline);

		QRegExp pattern;
		QTextCharFormat format;
	};

	std::vector<HighlightingRule> rules_;
};

#endif
