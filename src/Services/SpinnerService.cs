public interface ISpinnerService
{
    event Action? OnShow;
    
    event Action? OnHide;

    void Show();

    void Hide();
}

public class SpinnerService : ISpinnerService
{
    public event Action? OnShow;
    public event Action? OnHide;

    public void Show()
    {
        OnShow?.Invoke();
    }

    public void Hide()
    {
        OnHide?.Invoke();
    }
}