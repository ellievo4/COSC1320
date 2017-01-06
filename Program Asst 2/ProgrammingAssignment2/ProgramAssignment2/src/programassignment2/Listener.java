//COSC 1320 Summer 2015
//Thanh Vo
//Program Assignment 2
//This is my own work, I will not post

package programassignment2;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

//**********************************************
//Listener.java
//**********************************************
public class Listener implements ActionListener
{
    private View v = null;                  //track access to class View
    private Controller cont = new Controller();     //track access to class COntroller

    //--------------------------------
    //set View object v to view passed through parameter
    //--------------------------------
    public void setPointer(View view)
    {
        v = view;
    }

    //-------------------------------------------
    //control the action that is performed after user hit 1 of 4 buttons
    //-------------------------------------------
    public void actionPerformed(ActionEvent e)
    {
        //get command from user clicking button
        String act = e.getActionCommand();

        //match each case of button pressed with the action in class Controller
        if (act.equals("OpenSwitch 1"))
            cont.UCOpen1(v);
        if (act.equals("CloseSwitch 1"))
            cont.UCClose1(v);
        if (act.equals("OpenSwitch 2"))
            cont.UCOpen2(v);
        if (act.equals("CloseSwitch 2"))
            cont.UCClose2(v);
    }
}
