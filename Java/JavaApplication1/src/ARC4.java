
import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.geom.Arc2D;
import java.awt.geom.Rectangle2D;
import javax.swing.JFrame;


public class ARC4 extends JFrame{
    public ARC4() {
        setTitle("ARC");
        setSize(800, 800); // Dimensions of the window
        
        setLocation(100, 100); // Determine the intiliaze place of the window on the screen
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //Close the window by clicking cancle
        setLocationRelativeTo(null);// Make the intiliaze place of the window in the middle screen 
        setVisible(true); // Show the window
    }

    public void paint(Graphics g) {
        super.paint(g);
        Graphics2D gg = (Graphics2D) g;
        gg.setColor(Color.blue);
        gg.setStroke(new BasicStroke(3));// To increase the font width
        gg.setFont(new Font("Arial",Font.BOLD,20));
        gg.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
        gg.drawString("محمد محمود السيد احمد (20)", 300, 150);
        drawingArc(gg);
    }

    private void drawingArc(Graphics2D art){
        art.setColor(Color.yellow);
        //First
//        art.fillArc(-200, -170, 400, 400, 270, 90);
        
        //Second
//        Arc2D a = new Arc2D.Double(-200, -170, 400, 400, 360, -90, Arc2D.PIE);
//        art.fill(a);
        
        //Third
//        Arc2D a = new Arc2D.Double(-200, -170, 400, 400, 0, -90, Arc2D.PIE);
//        art.fill(a);
        
        //Fourth
//        Rectangle2D r = new Rectangle2D.Double(-200, -170, 400, 400);
//        art.draw(r);
//        Arc2D a = new Arc2D.Double(-200, -170, 400, 400, -90, 90, Arc2D.PIE);
//        art.fill(a);
    }

    public static void main(String[] args) {
        // TODO code application logic here
        System.out.println("Hello World");
        ARC4 m = new ARC4();
    }
}
