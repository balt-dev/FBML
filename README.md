# FBML
A DLL patch for Fractal Block World that allows you to reset the Lua environment to base, giving you access to all Lua libraries, including `os`, `debug`, and other things.

# A word of warning
These libraries were excluded from the game _for a reason_. It is entirely possible to **write a virus into a package** with this patch installed.

If a package tells you to install this before using it, _double check its code_. It very well could be trying to infect your computer.

If you do not trust this patch to not install a virus, do not install it. DLL injection is akin to running an executable on your computer. Don't be a dumbass. 

# Installation
- If your game version is not currently `v1.01.29`, wait for the repository to be updated for your version. (Last update: 8-15-2025 18:02 UTC)
- Rename `Fractal Block World/Bin/zlib1.dll` to `Fractal Block World/Bin/zlib1-orig.dll`
- Download from Releases, and save as `Fractal Block World/Bin/zlib1.dll`
- Launch the game

# Usage
**Check that libraries have not been loaded first,** and then call `fixlibs()`.
```lua
if not os then fixlibs() end
```
