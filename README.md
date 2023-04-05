# 🌈 Blazor Color Palette Generator 🚀
[![dotnet 7.0](https://img.shields.io/badge/.NET%207.0-blueviolet?style=for-the-badge&logo=dotnet)](https://dotnet.microsoft.com/)
![Blazor](https://img.shields.io/badge/blazor-blueviolet.svg?style=for-the-badge&logo=blazor&logoColor=white)
![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Webassembly](https://img.shields.io/badge/Webassembly-mediumslateblue.svg?style=for-the-badge&logo=webassembly&logoColor=white)
[![Repo License](https://img.shields.io/github/license/jkher/summarize-email?style=for-the-badge)](https://github.com/jkher/BlazorPaletteGenerator/blob/master/LICENSE.txt)

Blazor Color Palette Generator is a sample .NET Blazor webassembly application that allows users to extract color palettes from selected image (JPEG/PNG). The color palette extraction code is written in C++. The C++ is added as native dependency to blazor webassembly and uses [stb_image.h library](https://github.com/nothings/stb/blob/master/stb_image.h) to load image from byte[] passed from application.

This application was created as an exprimentation to demonstate adding [ASP.NET Core Blazor WebAssembly native dependencies](https://learn.microsoft.com/en-us/aspnet/core/blazor/webassembly-native-dependencies?view=aspnetcore-7.0) introduced in .NET7 to blazor wasm.

![Demo](https://github.com/jkher/BlazorPaletteGenerator/blob/master/Demo.gif?raw=true)

See the working [Demo](https://jkher.github.io/BlazorPaletteGenerator/) of this application hosted on github pages.

