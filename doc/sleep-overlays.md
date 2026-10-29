# Custom sleep-screen overlays

Choose **Settings > Sleep screen > Book cover with custom overlay** in Kobalt
to combine the current publication's cover with a transparent PNG. This uses
Kobalt's cover for the open book, rather than Nickel's last native reading cover.
The mode is opt-in; the default and existing cover/page modes are unchanged.

Place your artwork at `sleep-overlay.png` in the Kobalt profile. On Kobo, this
is `.adds/kobalt/sleep-overlay.png`. Transparent pixels reveal the cover;
semi-transparent pixels blend with it. Use your screen's dimensions for the
best result. Other dimensions are stretched to fit the complete screen. The
original file is never modified. Existing Nickel Screensaver PNG artwork can
be copied to this path; Nickel Screensaver itself is not required.

The completed screen has no Kobalt status card, so the artwork is not covered
by progress or charging labels. If the book has no usable cover, its current
reading page is used instead. Missing, invalid, non-transparent or oversized
artwork falls back to the ordinary Kobalt cover screen, including its status
card. PNG files must be at most 4 MiB encoded and 4,194,304 decoded pixels.
The optional mode retains settings format version 1 and does not invalidate
reading data or document caches. Older builds do not support the new mode.

Artwork is read and composited before the sleep handoff. It is not reloaded
during sleep or on charging updates. Replacing it takes effect on the next
sleep. Reader-page pixels, source artwork and saved book state are unchanged.

Native lifecycle tests cover alpha blending, bounds, invalid inputs, missing
cover fallback, charging updates and wake cleanup. These controlled host tests
do not establish physical Kobo display behavior or compatibility with another
add-on's power hooks. In particular, an add-on that replaces Kobalt's sleep
handler without chaining it can still prevent the handoff from running.
