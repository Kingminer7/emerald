#pragma once

npCallP(geode::MDConfig, regFont, setFontRegular, (geode::BitmapFont* font), (font))
npCallP(geode::MDConfig, boldFont, setFontBold, (geode::BitmapFont* font), (font))
npCallP(geode::MDConfig, italicFont, setFontItalic, (geode::BitmapFont* font), (font))
npCallP(geode::MDConfig, boldItalicFont, setFontBoldItalic, (geode::BitmapFont* font), (font))
npCallP(geode::MDConfig, monoFont, setFontMono, (geode::BitmapFont* font), (font))
npCallP(geode::MDConfig, fontScale, setFontScale, (float scale), (scale))
npCallP(geode::MDConfig, headingScale, setHeadingScale, (std::array<float, 6> const& scales), (scales))
npCallP(geode::MDConfig, headingScale, setHeadingScale, (uint8_t level, float scale), (level, scale))
npCallP(geode::MDConfig, linkColor, setLinkColor, (cocos2d::ccColor3B color), (std::move(color)))
npCallP(geode::MDConfig, linkActiveColor, setLinkActiveColor, (cocos2d::ccColor3B color), (std::move(color)))
npCallP(geode::MDConfig, paragraphSpacing, setParagraphSpacing, (float spacing), (spacing))

npCallP(geode::MDConfig, listIndent, setListIndent, (float indent), (indent))
npCallP(geode::MDConfig, listBulletMarker, setListBulletMarker, (std::string marker), (std::move(marker)))
npCallP(geode::MDConfig, listOrderedSeparator, setListOrderedSeparator, (std::string separater), (std::move(separater)))
npCallP(geode::MDConfig, listMarkerOpacity, setListMarkerOpacity, (GLuint opacity), (opacity))

npCallP(geode::MDConfig, codeBlockIndent, setCodeBlockIndent, (float indent), (indent));
npCallP(geode::MDConfig, codeBlockPadding, setCodeBlockPadding, (float padding), (padding));
npCallP(geode::MDConfig, codeBlockBgScale, setCodeBlockBgScale, (float scale), (scale));
npCallP(geode::MDConfig, codeBlockBgOpacity, setCodeBlockBgOpacity, (GLubyte opacity), (opacity));
npCallP(geode::MDConfig, codeBlockBgColor, setCodeBlockBgColor, (cocos2d::ccColor3B color), (std::move(color)));
npCallP(geode::MDConfig, codeSpanBgScale, setCodeSpanBgScale, (float scale), (scale));
npCallP(geode::MDConfig, codeSpanBgExtraWidth, setCodeSpanBgExtraWidth, (float width), (width));
npCallP(geode::MDConfig, codeSpanBgOffsetY, setCodeSpanBgOffsetY, (float offset), (offset));
npCallP(geode::MDConfig, codeSpanTextOffsetY, setCodeSpanTextOffsetY, (float offset), (offset));
npCallP(geode::MDConfig, codeSpanBgOpacity, setCodeSpanBgOpacity, (GLubyte opacity), (opacity));
npCallP(geode::MDConfig, codeSpanBgColor, setCodeSpanBgColor, (cocos2d::ccColor3B color), (std::move(color)));

npCallP(geode::MDConfig, hrPaddingBefore, setHrPaddingBefore, (float padding), (padding));
npCallP(geode::MDConfig, hrPaddingAfter, setHrPaddingAfter, (float padding), (padding));

npCallP(geode::MDConfig, imageDefaultScale, setImageDefaultScale, (float value), (value));
npCallP(geode::MDConfig, imageMinScale, setImageMinScale, (float value), (value));
npCallP(geode::MDConfig, imageMaxDim, setImageMaxDim, (float value), (value));

npCallP(geode::MDConfig, blockQuoteIndent, setBlockQuoteIndent, (float indent), (indent));
npCallP(geode::MDConfig, blockQuoteRuleWidth, setBlockQuoteRuleWidth, (float width), (width));
npCallP(geode::MDConfig, blockQuoteRuleColor, setBlockQuoteRuleColor, (cocos2d::ccColor3B color), (std::move(color)));

npCallP(geode::MDConfig, tableCellPadding, setTableCellPadding, (float padding), (padding));
npCallP(geode::MDConfig, tableBorderWidth, setTableBorderWidth, (float width), (width));
npCallP(geode::MDConfig, tableHeaderBgOpacity, setTableHeaderBgOpacity, (GLubyte opacity), (opacity));
npCallP(geode::MDConfig, tableBorderColor, setTableBorderColor, (cocos2d::ccColor3B color), (std::move(color)));
npCallP(geode::MDConfig, tableHeaderBgColor, setTableHeaderBgColor, (cocos2d::ccColor3B color), (std::move(color)));