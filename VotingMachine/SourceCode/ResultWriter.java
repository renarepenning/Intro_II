/**
* ResultWriter class takes in a file to print to and a ballot object, that has been "voted on by users
		Formats results of election into an output, writes into a file created in Voting Machine
		directory.
*/
import java.io.IOException;
import java.io.*;
import java.lang.*;
import java.nio.file.*;
import java.util.*;

public class ResultWriter
{
  /**
  *		Writes election results, formatted, into an output file in VotingMachine directory.
	* Output file is created and named electionResults.txt
  * @param filename
	* @param ballot
  */
	public static void writeResults(String filename, Ballot ballot)
	throws IOException
	{
		// create a new file and FileWriter object to enter election results
		File outputFile = new File("electionResults.txt");
		FileWriter writeToFile = new FileWriter(outputFile);
		// creates PrintWriter to 'print' the FileWriter object to the file
		PrintWriter printToFile = new PrintWriter(writeToFile);

		// Retrieve array list of candidates from the ballot
		ArrayList<Candidate> candidates = new ArrayList<Candidate>(ballot.getCandidates());
		//Create an array to hold lines of the file
		String resultLines[] = new String[candidates.size() + 4]; //

		// TITLE LINE
		resultLines[0] = "RESULTS - " + ballot.getOfficeName();
		// DASH line
		int dashes = resultLines[0].length();
		resultLines[1] = "-";
		for (int i = 0; i < dashes - 1; i++)
			{	resultLines[1] = resultLines[1] + "-"; }
		// SECOND TO LAST LINE
		resultLines[candidates.size() + 2] = " ";

		// RESULT LINES
		for (int i = 2; i < candidates.size() + 2; i++) {
			resultLines[i] = candidates.get(i - 2).getName() + " - " + candidates.get(i - 2).getAffiliation();
		}

		// FINAL LINE
		String lastLine = "";
		int votesMax = -1; // set vote max below minimum so we have no false winners/ties
		for (int i = 0; i < candidates.size(); i++)
		{
			String currentName = candidates.get(i).getName();
			String currentAffiliation = candidates.get(i).getAffiliation();
			int voteCt = candidates.get(i).getVoteCount();
			//Determine if we have new max amt of votes or a tie
			if (voteCt > votesMax) {
				lastLine = "WINNER: " + currentName + " - " + currentAffiliation;
				votesMax = voteCt;
			}
			else if (voteCt == votesMax) {
				lastLine = "NO WINNER";
			}
		}
		resultLines[candidates.size() + 3] = lastLine;


		/** print contents of each array into "printToFile" - our PrintWriter */
		printToFile.printf( resultLines[0] );
		printToFile.printf( "\n" + resultLines[1] );
		//
		// figure out how to set 12 spaces right of longest line
		//
		//
		for (int i = 2; i < candidates.size() + 2; i++)
		{
			//	gets number of votes from original Candidate object,
			//and formats then in with the info held in array
			int numVotes = candidates.get(i-2).getVoteCount();
			printToFile.printf("\n%-40s%d", resultLines[i], numVotes);
		}
		printToFile.printf("\n" + resultLines[candidates.size() + 2] );
		printToFile.printf("\n" + resultLines[candidates.size() + 3] );

		//End writing into file
		printToFile.close();
	}
}
