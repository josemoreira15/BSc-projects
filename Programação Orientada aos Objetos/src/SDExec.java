import javax.swing.text.html.parser.Parser;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;


public class SDExec {

    public static void main(String [] args) throws IOException, ClassNotFoundException {
        Parse parse = new Parse();
        Scanner scanner1 = new Scanner(System.in);
        Scanner scanner2  = new Scanner(System.in);


        Menu menu = new Menu(false,parse.parse(),scanner1,scanner2,1);
        menu.runMenu();

        scanner1.close();
        scanner2.close();
    }
}
