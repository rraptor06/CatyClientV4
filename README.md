# 🚀 **CatyClientV4**
The new version of the **CatyClient** for **Minecraft: Wii U Edition** + **open source**. 🎮✨

---

## 🛠️ **Building**
### 📦 **Applications Requirements**
- You need to install [DevkitPro](https://github.com/devkitPro/installer/releases) and [Python3](https://www.python.org/downloads).
### 📚 **Libraries Requirements**
- [Wii U Plugin System (WUPS)](https://github.com/wiiu-env/WiiUPluginSystem) 🌐
- [Wii U Module System (WUMS)](https://github.com/wiiu-env/WiiUModuleSystem) 🛠️
- [libkernel](https://github.com/wiiu-env/libkernel) 🔧
- [libmocha](https://github.com/wiiu-env/libmocha) ☕
- [wiiload_plugin](https://github.com/wiiu-env/wiiload_plugin) 📲
1. Install the required packages with pacman: `pacman -Syu --needed wiiu-dev`.
2. Download the zip files for WUPS, WUMS & libkernel and extract them.
3. Run `make install` inside each of the extracted folders.
4. Download the WiiLoad Plugin zip file & extract it, then copy the wps file to your Wii U SD card plugins folder (/vol/external01/wiiu/environments/aroma/plugins).
### ⚡ Compiling
1. After, run `make` for compile the CatyClient V4 Aroma Plugin.
2. If you want to clean the build folder, run `make clean`.

---

## 💬 **Discord Server**
Join our **Discord server** to connect with the community and get the latest updates! 🔥  
👉 [**Click here to join**](https://discord.gg/cR6Wpp9W) 👈

---