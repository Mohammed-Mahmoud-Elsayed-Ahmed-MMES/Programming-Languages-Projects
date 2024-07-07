/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
/* The Secret in this task is begining from random to the end of the loop
And the most important is the function of getWidth(), getHeight() inside x,y 
that make the stars spreads according to the width and height of the window */
import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Line2D;
import javax.swing.JFrame;
import java.util.Random;

public class Stars extends JFrame {

    public Stars() {
        setTitle("Stars");
        setSize(500, 500); // Dimensions of the window
        setLocation(100, 100); // Determine the intiliaze place of the window on the screen
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //Close the window by clicking cancle
        setLocationRelativeTo(null);// Make the intiliaze place of the window in the middle screen 
        setVisible(true); // Show the window
    }
    //paint function enables us to draw on the window 
    public void paint(Graphics g) {
        super.paint(g);
        Graphics2D gg = (Graphics2D) g;
        gg.setStroke(new BasicStroke(3));// To increase the font width
        Line2D l = new Line2D.Double(100, 100, 200, 200);/* This code creates a new instance of the Line2D class and assigns it to the variable 'l'. 
        The line starts at the point (100, 100) and ends at the point (200, 200). The line is drawn using the Double precision floating-point values.*/
        gg.draw(l);
        gg.setColor(Color.white);
        Random rand = new Random();//<editor-fold defaultstate="collapsed" desc="comment">
                
        for (int i = 0; i < 100; i++) {
            int x = rand.nextInt(getWidth());
            int y = rand.nextInt(getHeight());
            gg.drawLine(x, y, x, y);
        }

//        gg.setBackground(Color.black);
    }

    public static void main(String[] args) {
        // TO DO code application logic here
        System.out.println("Hello World");
        Stars m = new Stars();
        m.getContentPane().setBackground(Color.black);//Make the background black

    }
}
