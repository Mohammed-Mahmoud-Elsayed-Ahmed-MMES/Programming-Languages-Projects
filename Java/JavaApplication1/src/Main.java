import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import javax.swing.JFrame;
import javax.swing.JPanel;

class House extends JPanel {

   public void paintComponent(Graphics g) {
      super.paintComponent(g);

      // set the background color
      setBackground(Color.blue);

      // draw the circle
      g.setColor(Color.RED);
      g.fillOval(50, 50, 100, 100);

      // draw the rectangle over the circle
      g.setColor(Color.BLUE);
      g.fillRect(75, 75, 50, 50);
      
      Graphics2D g2d = (Graphics2D) g; // cast to g2d
        
        // green floor
        g2d.setColor(Color.green);
        g2d.fillRect(0, 300, 500, 200);
        
        // black sky
        g2d.setColor(Color.black);
        g2d.fillRect(0, 0, 500, 300);
        
        // skeletal house framework
        g2d.setColor(Color.red);
        g2d.fillRect(100, 100, 300,300);
        g2d.drawLine(100, 100, 250, 50);
        g2d.drawLine(400, 100, 250, 50);
        
        // windows
        g2d.setColor(Color.white);
        g2d.fillRect(270, 120, 100, 100);
        g2d.setColor(Color.black);
        g2d.drawLine(320, 120, 320, 220);
        g2d.drawLine(270, 170, 370, 170);
        
        // door
        g2d.setColor(Color.white);
        g2d.fillRect(200, 250, 100, 150);

        g2d.setColor(Color.black);
        g2d.setStroke(new BasicStroke(4));
        g2d.drawLine(210, 300, 210, 300);
        
        // name
//        g2d.setColor(Color.black);
//        g2d.setFont(new Font("Arial", Font.BOLD, 20));
//        g2d.drawString("Saeed Ahmed Saeed", 150, 450);
   }
}

public class Main {

   public static void main(String[] args) {
      JFrame frame = new JFrame("Drawing Example");
      frame.add(new House());
      frame.setSize(800, 800);
      frame.setLocation(100,100);
      frame.setLocationRelativeTo(null);
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      frame.setVisible(true);
   }
}