using System.Runtime.InteropServices;

interface IPaletteGenerationService
{
    Task<List<Palette>?> GeneratePalettesAsync(byte[] imageBuffer);
}

class PaletteGenerationService : IPaletteGenerationService
{
    [DllImport("img2palette", CallingConvention = CallingConvention.Cdecl)]
    public static extern IntPtr generate_palette(IntPtr bytes, int length, out int totalBuckets);

    public async Task<List<Palette>?> GeneratePalettesAsync(byte[] imageBuffer)
    {
        return await Task.Run(() =>
        {
            List<Palette>? palettes = null;

            IntPtr unmanagedArray = Marshal.AllocHGlobal(imageBuffer.Length);
            Marshal.Copy(imageBuffer, 0, unmanagedArray, imageBuffer.Length);

            int totalBuckets = 0;
            IntPtr paletteArray = generate_palette(unmanagedArray, imageBuffer.Length, out totalBuckets);

            int arrayLength = Marshal.ReadInt32(paletteArray);
            palettes = new List<Palette>();
            for (int i = 0; i < totalBuckets; ++i)
            {
                var data = new IntPtr(paletteArray.ToInt64() + Marshal.SizeOf(typeof(Palette)) * i);
                var palette = (Palette)Marshal.PtrToStructure(data, typeof(Palette))!;
                palettes.Add(palette);
            }

            Marshal.FreeHGlobal(unmanagedArray);

            return palettes;
        });
    }
}