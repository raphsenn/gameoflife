

class UserInput{

private:
    int mouseRow_;
    int mouseCol_;

public:
    int keycode_;
    bool isPressed_Space();
    bool isPressed_q();
    int getMouseCol();
    int getMouseRow();
    bool mouseClicked();  
    void handleMouseEvent();



};
