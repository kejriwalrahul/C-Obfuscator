import syntaxtree.*;
import visitor.*;

public class ParserMain {
   public static void main(String [] args) {
      try {
         Node root = new CParser(System.in).Goal();
         Translator t = new Translator();
         root.accept(t);
      }
      catch (ParseException e) {
         System.out.println(e.toString());
      }
   }
} 


