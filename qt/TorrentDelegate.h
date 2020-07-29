/*
 * This file Copyright (C) 2009-2015 Mnemosyne LLC
 *
 * It may be used under the GNU GPL versions 2 or 3
 * or any future license endorsed by Mnemosyne LLC.
 *
 */

#pragma once

#include <optional>

#include <QStyledItemDelegate>

class QStyle;
class QStyleOptionProgressBar;

class Torrent;

class TorrentDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit TorrentDelegate(QObject* parent = nullptr);

    // QAbstractItemDelegate
    QSize sizeHint(QStyleOptionViewItem const& option, QModelIndex const& index) const override;
    void paint(QPainter* painter, QStyleOptionViewItem const& option, QModelIndex const& index) const override;

protected:
    QSize margin(QStyle const& style) const;
    void setProgressBarPercentDone(QStyleOptionViewItem const& option, Torrent const&) const;
    QIcon& getWarningEmblem() const;

    // Our own overridables
    virtual QSize sizeHint(QStyleOptionViewItem const&, Torrent const&) const;
    virtual void drawTorrent(QPainter* painter, QStyleOptionViewItem const& option, Torrent const&) const;

    static QString statusString(Torrent const& tor);
    static QString progressString(Torrent const& tor);
    static QString shortStatusString(Torrent const& tor);
    static QString shortTransferString(Torrent const& tor);

    static QColor blue_brush;
    static QColor green_brush;
    static QColor silver_brush;
    static QColor blue_back;
    static QColor green_back;
    static QColor silver_back;

    mutable QStyleOptionProgressBar progress_bar_style_ = {};

private:
    mutable std::optional<int> height_hint_;
    mutable QFont height_font_;
    mutable QIcon warning_emblem_;
};
