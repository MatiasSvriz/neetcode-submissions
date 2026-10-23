class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int left = 0;
        int right = 0;

        int maxLength = 0;

        unordered_map<char, int> frequency;

        while(right < s.size()){

            // Ampliamos la ventana incorporando la letra de la derecha.
            frequency[s[right]] ++;

            // Comprobamos la ventana y la reducimos si necesita más de k reemplazos.
            while(true){

                int maxFrequency = 0;

                for(const auto& [character, freq] : frequency){

                    maxFrequency = max(freq, maxFrequency);

                }

                int length = right - left + 1;
                int replacementNeeds = length - maxFrequency;

                if(replacementNeeds <= k){

                    // La ventana es válida, dejamos de reducirla.
                    break;

                }else{

                    // Necesitamos demasiados reemplazos.
                    // Quitamos la letra de la izquierda y avanzamos
                    // el límite para volver a comprobar la ventana.
                    frequency[s[left]] --;
                    left ++;

                }

            }

            // La ventana ya es válida. Actualizamos la mejor longitud.
            int length = right - left + 1;
            maxLength = max(maxLength, length);

            // Intentamos apliar la ventana.
            right++;

        }

        return maxLength;

    }
};
