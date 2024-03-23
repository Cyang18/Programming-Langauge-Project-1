import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class file{
    static long startTime = System.nanoTime();
    public static void main(String[] args){

        try{
            BufferedWriter write = new BufferedWriter(new FileWriter("output.txt"));
            write.write("\r\n" + //
                                "In the ancient kingdom of Eldoria, where the moon cast its silver light upon the rolling hills and the stars danced in the midnight sky, there lived a young maiden named Elara. She was known throughout the land for her kindness and compassion, her heart as pure as the crystal-clear waters of the river that flowed through the heart of Eldoria.\r\n" + //
                                "From a young age, Elara had dreamed of exploring the farthest reaches of the kingdom, of venturing beyond the borders of her village to discover the wonders that lay beyond. But as the daughter of a humble farmer, her dreams seemed destined to remain just that - dreams.\r\n" + //
                                "One day, while tending to the fields on the outskirts of the village, Elara stumbled upon a hidden path leading into the depths of the forest. Intrigued, she followed it deeper and deeper into the woods, her senses alive with the sights and sounds of the wilderness.\r\n" + //
                                "As she walked, Elara heard a soft rustling in the underbrush, followed by the sound of delicate laughter. Curious, she quickened her pace, eager to discover the source of the mysterious sounds.\r\n" + //
                                "After what felt like hours of walking, Elara emerged into a sunlit clearing, the air alive with the hum of insects and the gentle rustle of leaves. And at its center stood a majestic oak tree, its branches stretching towards the sky like the outstretched arms of an old friend.\r\n" + //
                                "Mesmerized by its beauty, Elara approached cautiously, her heart pounding with excitement. And as she drew closer, she heard a soft voice emanating from the tree, gentle and soothing like a summer breeze.\r\n" + //
                                "\"Welcome, child of Eldoria,\" it whispered, its words echoing through the clearing. \"What brings you to this sacred place?\"\r\n" + //
                                "Startled but undeterred, Elara replied, \"I seek adventure and knowledge, noble tree. I long to explore the world beyond the borders of my village, to discover the wonders that lie beyond.\"\r\n" + //
                                "The oak tree chuckled softly, the sound like the rustling of leaves in the wind. \"Fear not, brave one. You have stumbled upon the Guardian Tree, a beacon of wisdom and guidance in a world filled with darkness. Tell me, what is it that you seek to learn?\"\r\n" + //
                                "With a sense of determination burning in her heart, Elara spoke from the depths of her soul. \"I seek knowledge of the world beyond Eldoria, of the lands and peoples that lie beyond our borders. I wish to learn of their customs and traditions, of their hopes and dreams.\"\r\n" + //
                                "The Guardian Tree shimmered with delight, its branches swaying gently in the breeze. \"Then so shall it be, brave adventurer. I shall grant you the gift of knowledge and understanding, that you may explore the world with an open heart and an open mind. But remember, true wisdom lies not in the accumulation of knowledge, but in the application of it for the betterment of all.\"\r\n" + //
                                "With a sense of purpose burning in her heart, Elara set out from the clearing, her mind filled with visions of the adventures that awaited her. And as she journeyed across the land, she encountered challenges both great and small, each one testing her courage and resolve.\r\n" + //
                                "Along the way, Elara made many friends and allies, each one adding their own strength to her cause. Together, they faced dark sorcerers, fierce monsters, and treacherous traps, their bonds growing stronger with each passing day.\r\n" + //
                                "But amidst the trials and tribulations, Elara never forgot the wisdom of the Guardian Tree. She showed kindness to those in need, offering aid to the downtrodden and standing up for the oppressed. And though she faced many hardships along the way, she knew that true wisdom lay not in the accumulation of knowledge, but in the application of it for the betterment of all.\r\n" + //
                                "And so, with each victory won and each challenge overcome, Elara's legend grew, her name spoken with reverence and awe by all who knew her. And though her journey was far from over, she knew that as long as she held fast to the lessons she had learned, she would always find the strength to face whatever trials lay ahead.\r\n" + //
                                "And so, with a smile on her lips and a twinkle in her eye, Elara continued her journey across the land, her heart filled with the courage and determination of a true adventurer. And though the road ahead would be long and fraught with danger, she knew that as long as she remained true to herself, she would always find her way home.\r\n" + //
                                "In the realm of Ardenia, where magic danced upon the breeze and the stars whispered secrets to those who listened, there lived a young adventurer named Finn. With his trusty sword at his side and a heart full of courage, Finn roamed the land in search of excitement and glory.\r\n" + //
                                "One day, while exploring the depths of an ancient forest, Finn stumbled upon a hidden glade bathed in golden light. At its center stood a majestic fountain, its waters shimmering with a mesmerizing glow. Intrigued by its beauty, Finn approached cautiously, his senses tingling with anticipation.\r\n" + //
                                "As he drew closer, a voice filled his mind, gentle yet powerful, like the echo of a distant melody. \"Welcome, traveler,\" it whispered, its words echoing through the glade. \"What brings you to this sacred place?\"\r\n" + //
                                "Startled but undeterred, Finn replied, \"I seek adventure and glory, noble fountain. I am but a humble adventurer, eager to explore the wonders of the world.\"\r\n" + //
                                "The fountain chuckled softly, the sound like the bubbling of water over smooth stones. \"Fear not, brave one. You have stumbled upon the Fountain of Dreams, a place of magic and wonder. Tell me, what is it that you desire most in this world?\"\r\n" + //
                                "Without hesitation, Finn spoke from the depths of his heart. \"I seek to prove myself as a hero, to face great challenges and emerge victorious. I long for adventure and excitement, to explore the farthest reaches of the land and make a name for myself among legends.\"\r\n" + //
                                "The Fountain of Dreams shimmered with delight, its waters glowing even brighter than before. \"Then so shall it be, brave adventurer. I shall grant you the boon of courage and strength, that you may face whatever trials lie ahead. But remember, true heroism lies not in the glory of battle, but in the kindness and compassion we show to others.\"\r\n" + //
                                "With a sense of determination burning in his heart, Finn set out from the glade, his mind filled with visions of the adventures that awaited him. And as he journeyed across the land, he encountered challenges both great and small, each one testing his courage and resolve.\r\n" + //
                                "Along the way, Finn made many friends and allies, each one adding their own strength to his cause. Together, they faced dark sorcerers, fierce monsters, and treacherous traps, their bonds growing stronger with each passing day.\r\n" + //
                                "But amidst the trials and tribulations, Finn never forgot the wisdom of the Fountain of Dreams. He showed kindness to those in need, offering aid to the downtrodden and standing up for the oppressed. And though he faced many hardships along the way, he knew that true heroism lay not in the glory of battle, but in the selfless acts of kindness that he showed to others.\r\n" + //
                                "And so, with each victory won and each challenge overcome, Finn's legend grew, his name spoken with reverence and awe by all who knew him. And though his journey was far from over, he knew that as long as he held fast to the lessons he had learned, he would always find the strength to face whatever trials lay ahead.\r\n" + //
                                "And so, with a smile on his lips and a twinkle in his eye, Finn continued his journey across the land, his heart filled with the courage and determination of a true hero. And though the road ahead would be long and fraught with danger, he knew that as long as he remained true to himself, he would always find his way home.\r\n" + //
                                "And so, in the quiet solitude of her cottage, Evelia continued her studies of the arcane arts, her mind filled with dreams of the adventures that awaited her in the world beyond. For though her journey had been long and arduous, she knew that the greatest adventures were yet to come.\r\n" + //
                                "And so, with a smile on her lips and a twinkle in her eye, Evelia closed her eyes and drifted off to sleep, knowing that tomorrow would bring with it a new day filled with endless possibilities.\r\n" + //
                                "\r\n" + //
                                "");
            write.close();
                              
    
        } catch (IOException e){
            e.printStackTrace();
        }
    
        long endTime = System.nanoTime();
        long duration = (endTime - startTime);
        System.out.println(duration / 1000);


        //write size is 7000 Characters

       
        
    
    }




}
