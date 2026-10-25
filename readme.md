# Emerald

Some various utilities I use in some of my mods.

## CMake Options

All of these can be toggled with `set(OPTION_NAME VALUE)` \
For example, `set(EMERALD_ADD_UIBUILDER ON)`

`EMERALD_ADD_UIBUILDER`: If Emerald should add UIBuilder to the project. Off by default. \
`EMERALD_SKIP_ALL`: If Emerald should skip building everything included in the library. \
`EMERALD_SKIP_ACTIONS`: If Emerald should skip building the actions included in the library. \
`EMERALD_SKIP_NODES`: If Emerald should skip building the nodes included in the library. \
`EMERALD_SKIP_UTILS`: If Emerald should skip building the utilities included in the library. Note that some are header only, so this won't apply to those. \
`EMERALD_BUILD_TESTS`: If Emerald should build the test mod.

If you want properties in DevTools, add `EMERALD_DEVTOOLS` to Emerald's compile definitions. Currently only applies to DragButton.

## Classes and methods

### Actions

`SizeTo`: Changes the content size of the node over time. \
This will probably be more useful with NineSlice than anything.

`TextTo`: Changes the text of the node over time. \
Supports nodes that inherit CCLabelProtocol (this includes geode::Label!)

### Nodes

`DragButton`: A class inheriting geode::Button that is draggable.

`MiniLayer`: A popup that wraps another class and drops down over the screen. Pass in the layer and its back button. \
Designed to look similar to how opening the shop looks.

### Utilities

`Intercepter`: A CCMenuItem callback replacer designed to act kind of like a hook for CCMenuItems, in a way. \
Stores itself in a CCArray user object, and should theoretically work with other interceptors. Based somewhat on CCMenuItemExt's implementation. \
Yes there is a typo in the class name, but I really don't feel like fixing it.

`NodeQuery`: A more convenient way to chain getting nodes. \
Includes id, id recursive, index, tag, type, sprite, and sprite frame.

`getSettingFast`: Caches the value of a setting and listens for changes, since getSettingValue can be slow if used a lot repeatedly. \
Not entirely sure who originally made it, it's been floating around geode for a while.

`GivePopupStandardIds`: Gives a popup standard ids, which should probably be added to geode itself at some point.

`GivePopupStandardIdsWithModId`: Sister macro to `GivePopupStandardIds`, just letting you specify a mod id instead of using _spr. \
Useful for libraries and templated popup headers.