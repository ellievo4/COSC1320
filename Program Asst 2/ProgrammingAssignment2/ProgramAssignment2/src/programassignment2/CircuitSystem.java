//COSC 1320 Summer 2015
//Thanh Vo
//Program Assignment 2
//This is my own work, I will not post

package programassignment2;

import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

//***************************
//CircuitSystem.java
//***************************
public class CircuitSystem
{
    private String label1;      //track the label for introduction
    private String label2;      //track the label for power supply
    private String label3;      //track the label for switch
    private String label4;      //track the label for light bulb

    //-----------------------
    //constructor for this class
    //-----------------------
    public CircuitSystem()
    {
        label1 = new String();
        label2 = new String();
        label3 = new String();
        label4 = new String();
    }

    //-------------------
    //load in label from the text file
    //-------------------
    public void load()
    {
        Scanner inFile = null;      //track the stream input

        //try-catch block to make sure there is a text file in the directory
        try
        {
            inFile = new Scanner(new FileInputStream("Programming Assignment 2 Data.txt"));
        }

        catch (FileNotFoundException e)
        {
            System.out.println("text file is not found");
            System.exit(0);
        }

        //stream in 4 labels
        this.label1 = inFile.nextLine();
        this.label2 = inFile.nextLine();
        this.label3 = inFile.nextLine();
        this.label4 = inFile.nextLine();
    }

    //-------------------------
    //return label 1 which is introduction
    //-------------------------
    public String getLabel1()
    {
        return label1;
    }

    //-------------------------
    //return label 2 which is power supply
    //-------------------------
    public String getLabel2()
    {
       return label2;
    }

    //-------------------------
    //return label 3 which is switch
    //-------------------------
    public String getLabel3()
    {
       return label3;
    }

    //-------------------------
    //return label 4 which is light bulb
    //-------------------------
    public String getLabel4()
    {
       return label4;
    }

    //-------------------------
    //operation when switch 1 is open
    //-------------------------
    public void open1(View v)
    {
       v.setSupply1(false);
       v.repaint();
    }

    //-------------------------
    //operation when switch 1 is close
    //-------------------------
    public void close1(View v)
    {
        v.setSupply1(true);
        v.repaint();
    }

    //-------------------------
    //operation when switch 2 is open
    //-------------------------
    public void open2(View v)
    {
       v.setSupply2(false);
       v.repaint();
    }

    //-------------------------
    //operation when switch 2 is close
    //-------------------------
    public void close2(View v)
    {
        v.setSupply2(true);
        v.repaint();
    }
}
