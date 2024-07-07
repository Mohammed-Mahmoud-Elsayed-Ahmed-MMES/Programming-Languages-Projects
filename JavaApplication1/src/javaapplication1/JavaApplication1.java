/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package javaapplication1;

/**
 *
 * @author admin
 */
import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Line2D;
import javax.swing.JFrame;
public class JavaApplication1 extends JFrame {

    /**
     */
    public JavaApplication1() {
        setTitle("Welcome");
        setSize(500,500); // Dimensions of the window
        setLocation(100,100); // Determine the intiliaze place of the window on the screen
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //Close the window by clicking cancle
        setLocationRelativeTo(null);// Make the intiliaze place of the window in the middle screen 
        setVisible(true); // Show the window
        
    }
    @Override
    public void paint(Graphics g){
        super.paint(g);
        Graphics2D gg = (Graphics2D) g;
        gg.setStroke(new BasicStroke(3));// To increase the font width
        gg.setColor(Color.blue);
        
        gg.drawLine(100, 100, 100, 200);
        gg.setColor(Color.red);
//        gg.drawLine(100,100,200,200); // The code as the two lines under it
        Line2D l = new Line2D.Double(100,100,200,200);// This code creates a new instance of the Line2D class and assigns it to the variable 'l'. The line starts at the point (100, 100) and ends at the point (200, 200). The line is drawn using the Double precision floating-point values.
        gg.draw(l);
        gg.setColor(Color.black);
        gg.drawLine(100, 200, 200, 200);
    }
    
    public static void main(String[] args) {
        // TODO code application logic here
       System.out.println("Hello World");
       JavaApplication1 m = new JavaApplication1();
    }
    
}
