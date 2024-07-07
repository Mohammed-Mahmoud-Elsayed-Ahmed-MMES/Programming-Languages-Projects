/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Font;
import java.awt.GradientPaint;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Polygon;
import java.awt.geom.GeneralPath;
import java.awt.geom.Line2D;
import java.awt.geom.Rectangle2D;
import javax.swing.JFrame;

public class House extends JFrame {

    public House() {
        setTitle("Rectangle");
        setSize(900, 800); // Dimensions of the window
        
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
        drawingSun(gg);
        drawingCloud(gg);
        drawingLine(gg);
        drawingKnob(gg);
        drawingLeaves(gg);
        
    }

    private void drawingRectangle(Graphics2D painter) {
        painter.setStroke(new BasicStroke(4));
       // green floor
        painter.setColor(new Color(255, 200, 1));
        painter.fillRect(0, 700, 900, 900);
        
        // black sky
        painter.setColor(new Color(135, 206, 234));
        painter.fillRect(0, 0, 900, 700);
        
        //tree trunk
        painter.setColor(new Color(129, 96, 61));
        painter.fillRect(80, 450, 35, 250);
        
        //chimney
        painter.setColor(Color.black);
        painter.fillRect(310, 270, 20, 70);
        
        //House
        painter.setColor(Color.blue);
        painter.fillRect(230, 390, 350, 310);
        
        //Window1
        painter.setColor(Color.white);
        painter.fillRect(250, 420, 70, 80);
        
        //Window2
        painter.setColor(Color.white);
        painter.fillRect(480, 420, 70, 80);
        
        //Door
        painter.setColor(Color.black);
        painter.fillRect(355, 540, 90, 160);

    }
    private void drawingLeaves(Graphics2D art){
        art.setStroke(new BasicStroke(4));
        art.setColor(new Color(0,255,1));
        art.fillRoundRect(20, 300, 160, 160, 160, 160);
    }
    
    private void drawingKnob(Graphics2D art){
        art.setStroke(new BasicStroke(4));
        art.setColor(new Color(167,124,79));
        art.fillRoundRect(360, 600, 20, 20, 20, 20);
    }
    
    private void drawingSun(Graphics2D art){
        art.setStroke(new BasicStroke(4));
        art.setColor(new Color(255,254,4));
        art.fillRoundRect(600, 200, 100, 100, 100, 100);
    }
    private void drawingLine(Graphics2D art){
        art.setStroke(new BasicStroke(4));
        art.setColor(Color.blue);
        
        art.drawLine(285, 420, 285, 520);
        art.drawLine(515, 420, 515, 520);
        
        art.setColor(new Color(244,18,214));
        GeneralPath path = new GeneralPath();
        path.moveTo(230, 390); // start here
        path.lineTo(400, 270);
        path.lineTo(580, 390);
        art.fill(path);
    }
    
    private void drawingCloud(Graphics2D art){
        art.setColor(Color.WHITE);
//        GeneralPath path = new GeneralPath();
        //1
        art.fillRoundRect(680, 210, 50, 50, 50, 60);
        art.fillRoundRect(725, 210, 50, 50, 50, 60);
        art.fillRoundRect(755, 240, 50, 50, 50, 60);
        art.fillRoundRect(710, 240, 50, 50, 50, 60);
        art.fillRoundRect(655, 240, 60, 55, 60, 60);
        
        //2
        art.fillRoundRect(400, 170, 50, 50, 50, 60);
        art.fillRoundRect(440, 170, 50, 50, 50, 60);
        art.fillRoundRect(480, 170, 50, 50, 50, 60);
        art.fillRoundRect(430, 195, 50, 50, 50, 60);
        art.fillRoundRect(460, 195, 50, 50, 50, 60);
        
        //3
        art.fillRoundRect(99, 218, 70, 70, 70, 70);
        art.fillRoundRect(100, 270, 90, 75, 90, 75);
        art.fillRoundRect(145, 220, 70, 70, 70, 70);
        art.fillRoundRect(155, 270, 80, 70, 80, 70);

    }

    public static void main(String[] args) {
        // TODO code application logic here
        System.out.println("Hello World");
        House m = new House();
    }
}