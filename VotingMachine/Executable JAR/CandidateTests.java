import static org.junit.jupiter.api.Assertions.*;
import org.junit.runner.RunWith;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.BeforeEach;

public class CandidateTests {
  private Candidate c1;
  private Candidate c2;
  private Candidate c3;
  //creates 4 tester candidates to run test methods on
  @BeforeEach
  public void setUp(){
    c1 = new Candidate("c1", "one");
    c2 = new Candidate("c2", "two");
    c3 = new Candidate("c3", "three");
  }
  /**

  */
  @Test
  public void testGetName()
  {
    assertEquals("c1", c1.getName());
    assertEquals("c2", c2.getName());
    assertEquals("c3", c3.getName());
  }

  @Test
  public void testGetAffiliation()
  {
    assertEquals("one", c1.getAffiliation());
    assertEquals("two", c2.getAffiliation());
    assertEquals("three", c3.getAffiliation());
  }

  @Test
  public void testGetVoteCount()
  {
    assertEquals(0, c1.getVoteCount());
    assertEquals(0, c2.getVoteCount());
    assertEquals(0, c3.getVoteCount());
  }

  @Test
  public void testTallyVote()
  {
    c1.tallyVote();
    assertEquals(1, c1.getVoteCount());
    c2.tallyVote();
    assertEquals(1, c2.getVoteCount());
    c3.tallyVote();
    assertEquals(1, c3.getVoteCount());
  }

  @Test
  public void testToString()
  {
    assertEquals("c1; one. 1 vote(s).", c1.toString());
    assertEquals("c2; two. 1 vote(s).", c2.toString());
    assertEquals("c3; one. 1 vote(s).", c3.toString());
  }


}
