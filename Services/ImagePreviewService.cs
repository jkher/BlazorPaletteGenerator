interface IImagePreviewService {
    Task<string> GetImageUriAsync(byte[] imageBytes);
}

class ImagePreviewService : IImagePreviewService {

    public async Task<string> GetImageUriAsync(byte[] imageBuffer)
    {
        return await Task.Run(() => {
            return $"data:image/png;base64,{Convert.ToBase64String(imageBuffer)}";
        });
    }

}