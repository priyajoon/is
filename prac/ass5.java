import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class ass5{
	public static String getMd5(String input){
		try{
			MessageDigest md=MessageDigest.getInstance("MD5");
			byte[] msg=md.digest(input.getBytes());
			BigInteger no=new BigInteger(1,msg);
			String hash=no.toString(16);
			while(hash.length()<32){
				hash="0"+hash;
			}
			return hash;
		}
		catch(NoSuchAlgorithmException e){
			throw new RuntimeException(e);
		}
	}

	public static void main(String args[]) throws NoSuchAlgorithmException{
		String s="hello";
		System.out.println("Hash = "+getMd5(s));
	}
}