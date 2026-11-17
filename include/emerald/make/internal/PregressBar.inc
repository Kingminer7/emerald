#pragma once

callP(geode::ProgressBar, style, setStyle, (geode::ProgressBar::Style style), (style))
callP(geode::ProgressBar, fillColor, setFillColor, (cocos2d::ccColor3B color), (std::move(color)))
callP(geode::ProgressBar, precision, setPrecision, (size_t precision), (precision))
callP(geode::ProgressBar, progress, updateProgress, (float value), (value))
callP(geode::ProgressBar, progress, updateProgress, (float value, float duration, EasingType ease = EasingType::None, geode::ProgressBar::AnimationCallback callback = nullptr), (value, duration, ease, std::move(callback)))
call(geode::ProgressBar, stopAnim, stopProgressAnimation)
callP(geode::ProgressBar, showLabel, showProgressLabel, (bool show), (show))
withOther(geode::ProgressBar, withProgressLabel, geode::Label, label, m_obj->getProgressLabel())
withOther(geode::ProgressBar, withBarFill, cocos2d::CCSprite, sprite, m_obj->getBarFill())
