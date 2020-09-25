/**
* Candidate class is used by Ballot class to represent an individual on the ballot.
* 		Has name, affiliation, and numVotes. Used with in the Ballot context throughout the program.
*/

public class Candidate
{
	/**The name of the Candidate*/
	private String name;
	/**Organization represented by candidate*/
	private String affiliation;
	/**Current number of votes given to Candidate */
	private int numVotes;
	/**
	*	Construct a Candidate
	* @param name the candidate's name
	* @param affiliation the organization which the person represents
	*/
	public Candidate(String name, String affiliation)
	{
		this.name = name;
		this.affiliation = affiliation;
	}
	/**
	* return Candidate's name
	* @return name
	*/
	public String getName()
	{		return this.name; 	}
	/**
	* return candidate's affiliation
	* @return affiliation
	*/
	public String getAffiliation()
	{		return affiliation;  }
	/**
	* returns amt of votes Candidate has
	* @return numVotes
	*/
	public int getVoteCount()
	{		return numVotes; }
	/**
	*  increments cadidate's votes by 1
	* @param none
	* @return none
	*/
	public void tallyVote()
	{
		numVotes++;
	}
	/**
	*  returns string with cadidate into
	* @param none
	* @return String
	*/
	public String toString()
	{
		return name + "; " + affiliation +". "+numVotes+" vote(s).";
	}
}
