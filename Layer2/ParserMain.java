import syntaxtree.*;
import visitor.*;

public class ParserMain {
   public static void main(String [] args) {
      try {
         Node root = new CParser(System.in).Goal();
         // System.out.println("Program parsed successfully");
         Pass1 x = new Pass1<String, String>();
         root.accept(x, null);
         root.accept(new Pass2<String, String>(x.g), null);
      }
      catch (ParseException e) {
         System.out.println(e.toString());
      }
   }
} 


