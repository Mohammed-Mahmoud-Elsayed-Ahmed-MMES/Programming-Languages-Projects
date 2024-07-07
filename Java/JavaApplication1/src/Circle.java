
import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Rectangle2D;
import javax.swing.JFrame;


public class Circle extends JFrame{
    public Circle() {
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
        drawingCircle(gg);
        gg.setFont(new Font("Arial",Font.BOLD,20));
        gg.drawString("محمد محمود السيد احمد (20)", 300, 150);
    }

    private void drawingCircle(Graphics2D art){
        art.setStroke(new BasicStroke(4));
        art.setColor(Color.blue);
        int width = 400;
        int height = 400;
        int Xc = 400;
        int Yc = 400;
        
        Ellipse2D e = new Ellipse2D.Double(10,100,50,90);
        art.fill(e);
//        int x = 200;
//        int y = 200;
        art.drawOval(Xc-width/2, Yc-height/2, width, height);
        art.drawLine(Xc, Yc, Xc, Yc);
        art.drawOval(Xc, Yc, width, height);
        art.drawRoundRect(300, 300, 80, 80, 80, 90);
//        art.fillRoundRect(350, 300, 100, 100, 100, 100);
    }

    public static void main(String[] args) {
        // TODO code application logic here
        System.out.println("Hello World");
        Circle m = new Circle();
    }
}
