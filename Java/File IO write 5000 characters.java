import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class file{
    static long startTime = System.nanoTime();
    public static void main(String[] args){

        try{
            BufferedWriter write = new BufferedWriter(new FileWriter("output.txt"));
            write.write("Once upon a time, in a land veiled by mist and shrouded in mystery, there existed a kingdom forgotten by time. This realm, known as Etherealum, lay hidden between the realms of mortals and spirits, its existence known only to a select few who dared to venture beyond the boundaries of the known world.\r\n" + //
                                "\r\n" + //
                                "Etherealum was a place of wonder and enchantment, where magic flowed like rivers and the very air crackled with energy. Its landscapes were as diverse as they were breathtaking, from rolling meadows adorned with vibrant wildflowers to towering mountains that scraped the heavens themselves.\r\n" + //
                                "\r\n" + //
                                "At the heart of Etherealum stood the Citadel of Lumina, a grand fortress of white stone that gleamed like a beacon in the eternal twilight. Within its walls, the rulers of Etherealum, the House of Argentum, reigned over their domain with wisdom and grace, their power derived from the ancient artifacts known as the Celestial Scepters.\r\n" + //
                                "\r\n" + //
                                "For centuries, the House of Argentum had safeguarded Etherealum from harm, ensuring that balance and harmony prevailed throughout the realm. But as the ages passed, whispers of discontent began to spread among the inhabitants of Etherealum. Some questioned the authority of the House of Argentum, while others harbored ambitions of seizing power for themselves.\r\n" + //
                                "\r\n" + //
                                "It was amidst this atmosphere of uncertainty that a young woman named Lyra was born. Lyra was unlike any other in Etherealum, her spirit imbued with a fiery determination that burned brighter than the sun. From a young age, she had dreamed of exploring the farthest reaches of Etherealum, uncovering its secrets and unlocking its mysteries.\r\n" + //
                                "\r\n" + //
                                "But Lyra's dreams were dashed when tragedy struck her family, leaving her orphaned and alone. With nowhere else to turn, she sought refuge within the walls of the Citadel of Lumina, where she was taken in by the House of Argentum as one of their own.\r\n" + //
                                "\r\n" + //
                                "Despite her misfortune, Lyra refused to be cowed by adversity. She threw herself into her studies, honing her skills in magic and combat with a fervor unmatched by any other. Her determination caught the eye of Lord Arion, the head of the House of Argentum, who saw in her the potential to become a formidable guardian of Etherealum.\r\n" + //
                                "\r\n" + //
                                "Under Lord Arion's tutelage, Lyra flourished, her talents blossoming like a flower in the spring. She proved herself time and time again, facing each challenge with courage and tenacity. And as she grew in strength and skill, whispers of her prowess spread throughout Etherealum, earning her the respect and admiration of all who knew her.\r\n" + //
                                "\r\n" + //
                                "But despite her accomplishments, Lyra could not shake the feeling that something was amiss in Etherealum. Dark omens lingered on the horizon, portents of a looming threat that threatened to engulf the realm in chaos. And try as she might, Lyra could not ignore the sense of unease that gnawed at her insides.\r\n" + //
                                "\r\n" + //
                                "One fateful night, as Etherealum lay bathed in the glow of the moon, a shadowy figure emerged from the depths of the forest, its eyes blazing with malice. It was none other than Malachai, a powerful sorcerer banished from Etherealum centuries ago for his wicked deeds.\r\n" + //
                                "\r\n" + //
                                "Driven by a thirst for vengeance, Malachai had spent centuries plotting his return, gathering an army of dark creatures to aid him in his quest to conquer Etherealum once and for all. And now, with his forces assembled and his power at its peak, he set his sights on the Citadel of Lumina, determined to crush the House of Argentum beneath his heel.\r\n" + //
                                "\r\n" + //
                                "As the citadel came under siege, Lyra sprang into action, rallying the defenders and leading them into battle against Malachai and his minions. The air crackled with magic as spells were cast and swords clashed, the fate of Etherealum hanging in the balance.\r\n" + //
                                "\r\n" + //
                                "For days the battle raged on, with neither side gaining the upper hand. But just when all seemed lost, Lyra unleashed a powerful incantation, channeling the very essence of Etherealum itself into a devastating blast that laid waste to Malachai's forces.\r\n" + //
                                "\r\n" + //
                                "But victory came at a cost, for in her moment of triumph, Lyra was struck down by a dark curse unleashed by Malachai himself. As she lay upon the battlefield, her life slipping away with each passing moment, she was visited by a vision of the ancient spirits of Etherealum, who offered her a chance at redemption.\r\n" + //
                                "\r\n" + //
                                "With their guidance, Lyra embarked on a perilous journey through the realms of both the living and the dead, facing trials and tribulations beyond imagination. Along the way, she encountered allies and adversaries alike, each offering their own wisdom and assistance on her quest.\r\n" + //
                                "\r\n" + //
                                "Finally, after what felt like an eternity, Lyra reached the heart of Etherealum, where she confronted Malachai in a final showdown for the fate of the realm. With the power of the Celestial Scepters coursing through her veins, she unleashed a barrage of magic unlike anything the world had ever seen, banishing Malachai from Etherealum once and for all.\r\n" + //
                                "\r\n" + //
                                "As the dust settled and peace was restored to Etherealum, Lyra was hailed as a hero, her name spoken with reverence and awe by all who dwelled within the realm. And though she had faced unimaginable hardships and sacrificed much along the way, she knew that her journey was far from over.\r\n" + //
                                "\r\n" + //
                                "For as long as there were threats to Etherealum, Lyra vowed to stand as its guardian, protecting it from harm and ensuring that its light would never be extinguished. And though her adventures would take her to the farthest reaches of the realm and beyond, she would always carry with her the lessons she had learned and the friendships she had forged along the way.\r\n" + //
                                "\r\n" + //
                                "And so, in the forgotten kingdom of Etherealum, the legend of Lyra, the guardian of light, lived on, a beacon of hope in a world shrouded in darkness.");
                                write.close();
                              
    
        } catch (IOException e){
            e.printStackTrace();
        }
    
        long endTime = System.nanoTime();
        long duration = (endTime - startTime);
        System.out.println(duration / 1000);


        //write size is 5000 Characters

       
        
    
    }




}
