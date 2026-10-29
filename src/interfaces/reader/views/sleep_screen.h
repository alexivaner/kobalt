#pragma once

#include <QImage>
#include <QString>
#include <QRect>

namespace kobalt::reader {
enum class SleepStatus { Sleeping, Charging, Charged };
QString sleepStatusText(SleepStatus status);
// Rounds up to whole minutes. Estimates above 120 minutes use hours and minutes.
// A negative estimate is unavailable and has no label.
QString sleepTimeLeft(qint64 milliseconds);
// Fits the cover without cropping. Unused space is always black.
QImage sleepCoverBackground(const QImage &cover, QSize size);
// Paint a bounded transparent PNG over an owned background. Invalid or missing
// artwork returns an empty image so the caller can use its ordinary sleep screen.
QImage sleepOverlayScreen(QImage background, const QString &path);
// Try up to 32 shuffled PNG candidates, then the explicit profile artwork.
// Each invocation chooses again; the completed image stays fixed during sleep.
QImage randomSleepOverlayScreen(QImage background, const QString &directory, const QString &fallback);
QRect sleepScreenCardRect(QSize size, bool showRemaining);
// Takes ownership of one background and paints in place. The caller
// releases the completed frame to the host before the device suspends.
QImage sleepScreenImage(QImage page, const QString &progress, const QString &remaining, bool dark,
                        int batteryPercent = -1, SleepStatus status = SleepStatus::Sleeping, bool dimPage = true);
}
