#pragma once

#include <QJsonObject>

namespace kobalt::sleep {
enum class Mode { Stock, Cover, Page, CoverOverlay };
inline constexpr Mode modes[] = {Mode::Stock, Mode::Cover, Mode::Page, Mode::CoverOverlay};
inline constexpr auto preferenceKey = "sleep_screen";
inline QString value(Mode mode) {
    switch (mode) {
    case Mode::Stock:
        return QStringLiteral("stock");
    case Mode::Cover:
        return QStringLiteral("cover");
    case Mode::Page:
        return QStringLiteral("page");
    case Mode::CoverOverlay:
        return QStringLiteral("cover_overlay");
    }
    return {};
}
inline Mode mode(const QJsonObject &preferences) {
    const auto saved = preferences.value(preferenceKey);
    if (saved.isUndefined()) {
        return preferences.value("kobalt_sleep_screen").toBool(false) ? Mode::Cover : Mode::Stock;
    }
    if (saved == value(Mode::Cover)) {
        return Mode::Cover;
    }
    if (saved == value(Mode::Page)) {
        return Mode::Page;
    }
    if (saved == value(Mode::CoverOverlay)) {
        return Mode::CoverOverlay;
    }
    return Mode::Stock;
}
inline bool usesCover(Mode mode) {
    return mode == Mode::Cover || mode == Mode::CoverOverlay;
}
}
