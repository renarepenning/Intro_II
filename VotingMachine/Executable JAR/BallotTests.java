import static org.junit.jupiter.api.Assertions.*;
import org.junit.runner.RunWith;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.BeforeEach;
import java.util.List;
import java.util.ArrayList;


public class BallotTests {
  private Ballot b1;
  private Ballot b2;
  //creates 2 tester ballots to run test methods on

  @BeforeEach
  public void setUp(){
    b1 = new Ballot("b1");
    Candidate c1 = new Candidate("c1", "one");
    b1.addCandidate(c1);

    b2 = new Ballot("b2");
    Candidate c2 = new Candidate("c2", "two");
    b2.addCandidate(c2);
  }
  /**

  */
  @Test
  public void testGetOfficeName(){
    assertEquals("b1", b1.getName());
    assertEquals("b2", b2.getName());
  }

  @Test
  public void testAddCandidate(){
    Candidate c1add = new Candidate("c1", "one");
    Candidate newC = new Candidate("rena", "Democrat");
    b1.addCandidate(newC);
    ArrayList c1s = new ArrayList<>(List.of(c1add, newC));
    assertEquals(c1s, b1.getCandidates());
  }

  @Test
  public void testGetCandidates(){
    Candidate c2a = new Candidate("c2", "two");
    ArrayList newCandArray = new ArrayList<>(List.of(c2a));
    assertEquals(c2s, b2.getCandidates());
  }


}
