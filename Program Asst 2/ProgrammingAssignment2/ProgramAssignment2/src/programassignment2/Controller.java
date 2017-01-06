//COSC 1320 Summer 2015
//Thanh Vo
//Program Assignment 2
//This is my own work, I will not post

package programassignment2;

//**********************
//Controller.java
//**********************
public class Controller
{
    private CircuitSystem sys = new CircuitSystem();    //track the access to class CircuitSystem

    //-------------------------
    //open switch 1
    //-------------------------
    public void UCOpen1(View v)
    {
        sys.open1(v);
    }

    //-------------------------
    //close switch 1
    //-------------------------
    public void UCClose1(View v)
    {
        sys.close1(v);
    }

    //-------------------------
    //open switch 2
    //-------------------------
    public void UCOpen2(View v)
    {
        sys.open2(v);
    }

    //-------------------------
    //close switch 2
    //-------------------------
    public void UCClose2(View v)
    {
        sys.close2(v);
    }
}
