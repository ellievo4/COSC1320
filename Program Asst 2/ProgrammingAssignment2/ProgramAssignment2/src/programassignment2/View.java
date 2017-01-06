//COSC 1320 Summer 2015
//Thanh Vo
//Program Assignment 2
//This is my own work, I will not post

package programassignment2;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JButton;
import java.awt.BorderLayout;
import java.awt.FlowLayout;
import javax.swing.JPanel;
import java.awt.Graphics;
import java.awt.Color;

//******************************
//View.java
//******************************
public class View extends JFrame
{
    private Listener ear = new Listener();                  //track the access to class Listener
    private CircuitSystem aSystem = new CircuitSystem();    //track the access to class CircuitSystem
    private boolean supply1;                                //track the status of switch 1
    private boolean supply2;                                //track the status of switch 2

    //----------------------------
    // constructor for this class
    //----------------------------
    public View()
    {
        //set frame
        super("Programing Assignment 2");
        setSize(500,500);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setLayout(new BorderLayout());

        //edit top panel
        JPanel topPanel = new JPanel();
        topPanel.setBackground(Color.WHITE);

        //add the very first label
        aSystem.load();
        JLabel label1 = new JLabel(aSystem.getLabel1());
        topPanel.add(label1);
        add(topPanel,BorderLayout.NORTH);

        //edit mid panel
        JPanel midPanel = new JPanel();
        midPanel.setBackground(Color.WHITE);
        add(topPanel,BorderLayout.CENTER);

        //edit bottom panel
        JPanel botPanel = new JPanel();
        botPanel.setBackground(Color.WHITE);
        botPanel.setLayout(new FlowLayout());

        //add the open1 button
        JButton openButton1 = new JButton("OpenSwitch 1");
        openButton1.setBackground(Color.BLACK);
        openButton1.addActionListener(ear);
        botPanel.add(openButton1);

        //add the close1 button
        JButton closeButton1 = new JButton("CloseSwitch 1");
        closeButton1.setBackground(Color.RED);
        closeButton1.addActionListener(ear);
        botPanel.add(closeButton1);

        //add the open1 button
        getContentPane().setBackground(Color.WHITE);
        JButton openButton2 = new JButton("OpenSwitch 2");
        openButton2.setBackground(Color.BLACK);
        openButton2.addActionListener(ear);
        botPanel.add(openButton2);

        //add the close1 button
        JButton closeButton2 = new JButton("CloseSwitch 2");
        closeButton2.setBackground(Color.RED);
        closeButton2.addActionListener(ear);
        botPanel.add(closeButton2);

        //add bottom panel
        add(botPanel,BorderLayout.SOUTH);
    }

    //-------------------------------------
    // set supply1 to equal the sw1 passed in method
    //
    public void setSupply1(boolean sw1)
    {
        supply1 = sw1;
    }

    //-------------------------------------
    // set supply2 to equal the sw2 passed in method
    //-------------------------------------
    public void setSupply2(boolean sw2)
    {
        supply2 = sw2;
    }

    //-----------------------------
    // set up the graphics of the whole circuit
    //-----------------------------
    @Override
    public void paint(Graphics g)
    {
        //call the super and the method getPointer in class Listener
        super.paint(g);
        ear.setPointer(this);
        
        //draw top line and label for light bulb
        g.drawLine(100,100, 225, 100);
        g.drawLine(275,100, 400, 100);
        g.drawString(aSystem.getLabel4(), 225, 150);

        //draw left side line and switch 1
        g.drawLine(100,100, 100, 150);
        g.drawLine(100,200,100,250);
        g.drawOval(92,150,17,17);
        g.drawOval(92, 183, 17, 17);
        g.drawLine(100,250,100,400);
        g.drawString(aSystem.getLabel3(), 25, 175);

        // draw mid line and power supply
        g.drawLine(100,250, 225, 250);
        g.drawLine(225,225,225,275);
        g.drawLine(250, 238, 250, 263);
        g.drawLine(250,250, 400, 250);
        g.drawString(aSystem.getLabel2(), 200, 290);
        
        //draw right side line and switch 2
        g.drawLine(400,100, 400, 250);
        g.drawLine(400,250,400,300);
        g.drawOval(392,300,17,17);
        g.drawOval(392, 333, 17, 17);
        g.drawLine(400,350,400,400);
        g.drawString(aSystem.getLabel3(), 425, 325);

        //draw bottom line
        g.drawLine(100,400, 225, 400);
        g.drawLine(275,400, 400, 400);
        g.drawString(aSystem.getLabel4(), 225, 360);

        // open and close switch 1 effect to the top oval
        if (supply1 == true)
        {
            g.setColor(Color.RED);
            g.drawLine(100, 167, 100, 183);
        }
        else
        {
            g.setColor(Color.BLACK);
            g.drawLine(75, 167, 100, 183);
        }
        g.drawOval(225, 75, 50, 50);

        // open and close switch 2 effect to the bottom oval
        if(supply2 == true)
        {
            g.setColor(Color.RED);
            g.drawLine(400, 317, 400, 333);
        }
        else
        {
            g.setColor(Color.BLACK);
            g.drawLine(375, 317, 400, 333);
        }
        g.drawOval(225, 375, 50, 50);
    }
}
