import syntaxtree.*;
import visitor.*;

public class ParserMain {
   public static void main(String [] args) {
      try {
         Node root = new CParser(System.in).Goal();
         // System.out.println("Program parsed successfully");
         UsedIdsGen u = new UsedIdsGen();
         root.accept(u);
         Translator t = new Translator();
         t.used = u.used;
         root.accept(t);
      }
      catch (ParseException e) {
         System.out.println(e.toString());
      }
   }
} 


