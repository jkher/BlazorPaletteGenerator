using BlazorPaletteGenerator;
using Microsoft.AspNetCore.Components.Web;
using Microsoft.AspNetCore.Components.WebAssembly.Hosting;

var builder = WebAssemblyHostBuilder.CreateDefault(args);
builder.RootComponents.Add<App>("#app");
builder.RootComponents.Add<HeadOutlet>("head::after");

builder.Services.AddScoped(sp => new HttpClient { BaseAddress = new Uri(builder.HostEnvironment.BaseAddress) });
builder.Services.AddScoped<IImagePreviewService, ImagePreviewService>();
builder.Services.AddScoped<IPaletteGenerationService, PaletteGenerationService>();
builder.Services.AddScoped<IClipboardService, ClipboardService>();
builder.Services.AddSingleton<ISpinnerService, SpinnerService>();

await builder.Build().RunAsync();
