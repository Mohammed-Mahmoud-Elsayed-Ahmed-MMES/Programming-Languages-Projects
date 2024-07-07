/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Line2D;
import java.awt.geom.Rectangle2D;
import javax.swing.JFrame;

public class Rectangle extends JFrame {

    public Rectangle() {
        setTitle("Rectangle");
        setSize(800, 800); // Dimensions of the window
        
        setLocation(100, 100); // Determine the intiliaze place of the window on the screen
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //Close the window by clicking cancle
        setLocationRelativeTo(null);// Make the intiliaze place of the window in the middle screen 
        setVisible(true); // Show the window
    }

    public void paint(Graphics g) {
        super.paint(g);
        Graphics2D gg = (Graphics2D) g;
        gg.setColor(Color.red);
        gg.setStroke(new BasicStroke(3));// To increase the font width
        drawingRectangle(gg);
        drawingCircle(gg);
        gg.setFont(new Font("Arial",Font.BOLD,20));
        gg.drawString("محمد محمود السيد احمد (20)", 300, 150);
    }

    private void drawingRectangle(Graphics2D painter) {
        painter.setStroke(new BasicStroke(4));
        painter.setColor(Color.red);
        //First way to draw a rectangle
        Rectangle2D r = new Rectangle2D.Double(500, 200, 50, 50);
        painter.fill(r);
        Rectangle2D s = new Rectangle2D.Double(250, 450, 50, 50);
        painter.fill(s);
        painter.setColor(Color.white);
        painter.drawRect(300, 250, 200, 200);

    }
    private void drawingCircle(Graphics2D art){
        art.setStroke(new BasicStroke(4));
        art.setColor(Color.blue);
        //Second way to draw a rectangle with (arcwidth:0,arcHeight:0) And To draw circle
        art.fillRoundRect(350, 300, 100, 100, 100, 100);
    }

    public static void main(String[] args) {
        // TODO code application logic here
        System.out.println("Hello World");
        Rectangle m = new Rectangle();
    }
}
