package com.predo;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class Main {

    public static void main(String[] args) {
	    File file = new File("arquivo.txt");

	    try {
            FileWriter fw = new FileWriter(file);
            fw.write("HEYYYYYYYYYYYYYYY");
            fw.append("Isso é bem mais fácil que C não vou negar");
            fw.flush();
            fw.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
