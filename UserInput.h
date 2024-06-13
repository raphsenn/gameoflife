

class UserInput{

private:
    int mouseRow_;
    int mouseCol_;

public:
    int keycode_;
    bool isPressed_Space();
    bool isPressed_q();
    bool isPressed_r();
    int getMouseCol();
    int getMouseRow();
    bool mouseClicked();
    bool isMouseEvent(int keycode); 
    void handleMouseEvent();



};
