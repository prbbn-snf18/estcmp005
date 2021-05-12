//Init
import java.util.HashMap;
import java.util.Random;

public class Run {
    public Run(){
        Random randNum = new Random();
        char[] alfa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ".toCharArray();
        char[] objetivo = "METHINKS IT IS LIKE A WEASEL".toCharArray();
        char[][] listaPalavras = fazerCopias(alfa, randNum);
        char[] melhorFilho = selecMelhor(listaPalavras,objetivo);
        
        System.out.println(String.valueOf(melhorFilho) + "ACERTOS: " + String.valueOf(acertos(melhorFilho, objetivo)));

        if(String.valueOf(melhorFilho).equals(String.valueOf(objetivo))){
            System.out.println("IGUAIS " + String.valueOf(melhorFilho));
        }else{
            int cont = 2;
            Boolean iguais = false;
            while(!(iguais)){
                listaPalavras = copiarSelecao(randNum, melhorFilho, alfa);
                melhorFilho = selecMelhor(listaPalavras, objetivo);
                if(String.valueOf(melhorFilho).equals(String.valueOf(objetivo))){
                    iguais = true;
                }else{
                    cont = cont + 1;
                }
            }
        }
    }

    public char[][] copiarSelecao(Random randNum, char[] melhorFilho, char[] alfa){
        String copiarMelhorF = String.valueOf(melhorFilho);
        char[][] listaPalavras = new char[100][28];
        for (int i = 0; i < 100; i++){
            char[] palavra = mutarPalavra(randNum, copiarMelhorF.toCharArray(), alfa);
            listaPalavras[i] = palavra;
        }
        return listaPalavras;
    }

    public char[] geraAleatorio(char[] listaCaracteres, Random rand){
        char[] palavra = new char[28];
        for (int i = 0; i < 28; i++){
            palavra[i] = listaCaracteres[rand.nextInt((26))];
        }
        return palavra;
    }

    public char[] mutarPalavra(Random rand, char[] palavra, char[] alfa){
        for (int i = 0; i < palavra.length; i++){
            if (rand.nextFloat() > 0.94){       //Valor pra compensar o arredondamento
                word[i] = alfa[rand.nextInt(26)];
            }
        }
        return palavra;
    }

    public char[][] fazerCopias(char[] listaCaracteres, Random rand){
        char[][] listaPalavras = new char[100][28];
        for (int i = 0; i < 100; i++){
            char[] palavra = mutarPalavra(rand, geraAleatorio(listaCaracteres, rand), listaCaracteres);
            listaPalavras[i] = palavra;
        }
        return listaPalavras;
    }

    public HashMap compare(char[] word, char[] target){
        HashMap<Integer, char[]> hm = new HashMap<>();
        int score = 0;
        for(int i = 0; i < 28; i++){
            if(word[i] == target[i]){
                score = score + 1;
            }
        }
        hm.put(score,word);
        return hm;
    }

    public char[] selecMelhor(char[][] listaPalavras, char[] objetivo){
        int acertos = 0;
        char[] vencedor = null;
        for (char[] palavra : listaPalavras){
            HashMap<Integer,char[]> hm = (compare(palavra, objetivo));
            for (Integer chave : hm.keySet()){
                if (chave > acertos){
                    acertos = chave;
                    vencedor = hm.get(key);
                }
            }
        }
        return vencedor;
    }
}